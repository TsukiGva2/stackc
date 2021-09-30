#ifndef CODEGEN_H
#define CODEGEN_H

/*#include <common.h> // (already included in lex.h)*/
#include <lex.h>
#include <cgen_errors.h>

typedef struct CodeGenerator {
     int expected;
     Token* last;
} CodeGenerator;

void
genC(TokStream* tokens, FILE* output);

#endif
