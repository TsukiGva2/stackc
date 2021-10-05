#ifndef CODEGEN_H
#define CODEGEN_H

/*#include <common.h> // (already included in lex.h)*/
#include <lex.h>
#include <cgen_errors.h>

typedef void (*Token_F)(Token*); /* void f(Token* t){} */

typedef struct Expect {
     int type;
     Token_F f;
     struct Expect* next;
} Expect;

enum States {
     ON_DEFINITION = (1u << 0),
};

typedef struct CodeGenerator {
     Token* last;
     uint16_t state;
     Expect* expected; /* array of expected tokens and what to do with them */
} CodeGenerator;

void
genC(TokStream* tokens, FILE* output);

#endif
