#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <common.h>

typedef struct Token { /* a linked list */
     char* lexeme;
     struct Token* next;
} Token;

typedef TokStream Token; /* a stream of tokens */

void
insertToken(TokStream* head, char* lexeme);

void
fdumpc(char* line, FILE* out);

#endif
