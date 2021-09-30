#include <lex.h>

extern const char* tokenTypes[9] = {
     "TOK_NO_TYPE",
     "TOK_WORD",
     "TOK_PLUS",
     "TOK_MINUS",
     "TOK_DIV",
     "TOK_MUL",
     "TOK_NUMBER",
     "TOK_COLON",
     "TOK_ANY"
};

static Token*
insertToken(TokStream* head, int type, const char* lexeme) {
     Token* tok = (Token*)malloc(sizeof(Token));

     tok->lexeme = NULL;
     tok->type = type;
     tok->next = NULL;

     if (lexeme != NULL) {
	  tok->lexeme = (char*)malloc(strlen(lexeme)+1);
	  strcpy(tok->lexeme, lexeme);
     }
     
     Token* curr;
     
     for (curr = head; curr->next != NULL; curr = curr->next);
     
     curr->next = tok;

     return tok;
}

static char*
getX(const char* text, const char** view, validate f) {
     int i = 0;
     for (const char* c = text; (*f)(*c); c++, i++);

     char* buf = (char*)malloc(i+1);
     strncpy(buf, text, i);

     *view += i;
     return buf;
}

static char*
getWord(const char* text, const char** view) {
     return getX(text, view, isalpha);
}

static char*
getNum(const char* text, const char** view) {
     return getX(text, view, isdigit);
}

void
freeTokStream(TokStream* head) {
     Token* next = head->next; /* make sure we do not free head */
     
     for (Token* curr = next; curr != NULL; curr = next) {
	  next = curr->next; /* keep curr->next after freeing */
	  
	  if (curr->lexeme != NULL)
	       free(curr->lexeme);
	  
	  free(curr);
     }
     
     free(head);
}

TokStream*
tokenize(const char* line) {
     TokStream* head = (TokStream*)malloc(sizeof(TokStream));
     head->type = TOK_NO_TYPE;
     head->next = NULL;

     int i = 0;
     
     for (const char* c = line; *c != '\0' && *c != '\n'; c++, i++) {
	  switch (*c) {
	  case '+':
	       insertToken(head, TOK_PLUS, NULL);
	       break;
	  case '-':
	       insertToken(head, TOK_MINUS, NULL);
	       break;
	  case '/':
	       insertToken(head, TOK_DIV, NULL);
	       break;
	  case '*':
	       insertToken(head, TOK_MUL, NULL);
	       break;
	  case ':':
	       insertToken(head, TOK_COLON, NULL);
	       break;
	  default:
	       if (isalpha(*c)) {
		    char* buf = getWord(c, &c);
		    insertToken(head, TOK_WORD, buf);
		    free(buf);
	       } else if (isdigit(*c)) {
		    char* buf = getNum(c, &c);
		    insertToken(head, TOK_NUMBER, buf);
		    free(buf);
	       }
	  }
     }

     return head;
}

