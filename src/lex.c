#include <lex.h>

static Token*
insertToken(TokStream* head, int type, const char* lexeme) {
     Token* tok = (Token*)malloc(sizeof(Token));

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
getWord(const char* text, const char** view) {
     int i = 0;
     for (const char* c = text; isalpha(*c); c++, i++);

     char* buf = (char*)malloc(i+1);
     strncpy(buf, text, i);

     *view += i;
     return buf;
}

static char*
getNum(const char* text) {
}

void
freeTokStream(TokStream* head) {
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
	  default:
	       if (isalpha(*c))
		    insertToken(head, TOK_WORD, getWord(c, &c));
	       else if (isdigit(*c))
		    insertToken(head, TOK_NUMBER, getNum(c));
	  }
     }

     return head;
}

