#ifndef LEXER_H
#define LEXER_H

#include <common.h>

enum TokenTypes {
     TOK_NO_TYPE,
     TOK_WORD,
     TOK_PLUS,
     TOK_MINUS,
     TOK_DIV,
     TOK_MUL,
     TOK_NUMBER,
};

typedef struct Token { /* a linked list */
     int type;
     char* lexeme;
     struct Token* next;
} Token;

typedef Token TokStream; /* a stream of tokens */

static Token*
insertToken(TokStream* head, int type, const char* lexeme);

/*
  those 'get' functions work by first creating a new view of the
  original text, then they get the size of that and strncpy it to
  the new char*. (which has to be manually free'd later)
*/
static char*
getWord(const char* text, const char** view);

static char*
getNum(const char* text);

void
freeTokStream(TokStream* head);

/*
  creates a stream of tokens from a line of code.
*/
TokStream*
tokenize(const char* line);

#endif
