#include <language.h>

void
fdumpc(char* line, FILE* out) { // TODO
     TokStream* head = tokenize(line);

#ifdef DEBUG
     for (Token* curr = head; curr != NULL; curr = curr->next)
	  printf("(%d, %s) ", curr->type, curr->lexeme);
#endif

     /*parse(head);*/
     
     freeTokStream(head);
}
