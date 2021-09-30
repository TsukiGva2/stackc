#include <codegen.h>



void
genC(TokStream* tokens, FILE* output) {
     CodeGenerator cgen = {TOK_ANY};
     Token* curr = tokens->next;
     
     for (; curr != NULL; curr = curr->next) {
	  if (curr->type != cgen.expected &&
	      cgen.expected != TOK_ANY) {
	       unexpectedTokenError(cgen.expected, curr->type);
	       return;
	  }

	  cgen.expected = TOK_ANY;
	  
	  switch (curr->type) {
	  case TOK_COLON:
	       cgen.expected = TOK_WORD;
	       fputs("int ", output);
	       break;
	  default:
	       unrecognizedTokenError(curr->type);
	       return;
	  }
     }
}
