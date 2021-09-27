#ifndef LANGUAGE_H
#define LANGUAGE_H
#include <common.h>

typedef struct Token { /* a linked list */
     char* lexeme;
     struct Token* next;
} Token;

void
fdumpc(char* line, FILE* out);

#endif
