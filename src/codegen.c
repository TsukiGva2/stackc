#include <codegen.h>

static void
initialize(FILE* output) {
     fputs("#include <string.h>\n"
	   "const char* lastIdentifier;"
	   "typedef struct Stack {\n"
	   "    void* top,\n"
	   "    void** elems,\n"
	   "    size_t size,\n"
	   "} Stack;\n"
	   "Stack* dataStack;\n"
	   "void* pop(Stack* stack) {\n"
	   "    void* top = stack->top;\n"
	   "    \n"
	   "    stack->top = stack->elems[0];\n"
	   "    return top;\n"
	   "}\n",
	   output);
}

void
genC(TokStream* tokens, FILE* output) {
     initialize(output);
     
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
