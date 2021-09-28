#include <language.h>

Token*
insertToken(TokStream* head, const char* lexeme) {
     Token* tok = (Token*)malloc(sizeof(Token));
     token.lexeme = lexeme; /* points to the same address */
     token.next = NULL;

     Token* curr;
     
     for (curr = head; curr->next != NULL; curr = curr->next);
     
     curr->next = tok;

     return tok;
}

void
fdumpc(char* line, FILE* out) { // TODO
     TokStream* head = NULL;

#ifdef DEBUG
     insertToken(head, "test");
     insertToken(head, "test");
     insertToken(head, "test");

     for (Token* curr = head; curr->next != NULL; curr = curr->next)
	  printf("%s\n", curr.lexeme);
#endif
     
     /*tokenize(head);*/
     /*parse(head);*/
}
