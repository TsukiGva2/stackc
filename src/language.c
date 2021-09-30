#include <language.h>

void
fdumpc(char* line, FILE* out) { // TODO
     TokStream* head = tokenize(line);

#ifdef DEBUG
     for (Token* curr = head; curr != NULL; curr = curr->next)
	  printf("(%d, %s) ", curr->type, curr->lexeme);
#endif

     /*
       yes, i'm skipping the parsing step, because
       this language doesn't need parsing at all,
       maybe i'll add it in when i implement a preprocessor
       but for now it's just unecessary.
      */

     /*genC(head);*/
     
     freeTokStream(head);
}
