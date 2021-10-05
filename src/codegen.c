#include <codegen.h>

static Expect*
insertToken(Expect* head, int type, Token_F f) {
     Expect* e = (Token*)malloc(sizeof(Expect));

     e->f    = NULL;
     e->type = type;
     e->next = NULL;

     Expect* curr;

     e->next = head->next;
     head->next = e;
     
     return e;
}

static void
initialize(FILE* output) {
}

void
genC(TokStream* tokens, FILE* output) {
     initialize(output);

     CodeGenerator cgen = {TOK_ANY, 0, NULL};
     Token* curr = tokens->next;

     cgen.expect = (Expect*)malloc(sizeof(Expect));
     
     for (; curr != NULL; curr = curr->next) {
	  if (curr->type != cgen.expected->type &&
	      cgen.expected->type != TOK_ANY) {
	       unexpectedTokenError(cgen.expected->type, curr->type);
	       return;
	  }

	  switch (curr->type) {
	  case TOK_COLON:
	       
	       break;
	  case TOK_SEMICOLON:
	       break;
	  case TOK_WORD:
	       break;
	  default:
	       unrecognizedTokenError(curr->type);
	       return;
	  }
     }
}
