#ifndef CODEGEN_H
#define CODEGEN_H

/*#include <common.h> // (already included in lex.h)*/
#include <lex.h>
#include <cgen_errors.h>

enum States {
     ON_DEFINITION = (1u << 0),
};

typedef struct CodeGenerator {
     int expected;
     Token* last;
     uint16_t state;
} CodeGenerator;

void
genC(TokStream* tokens, FILE* output);

#endif
