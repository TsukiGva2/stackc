#ifndef LEXER_H
#define LEXER_H

#include <common.h>

extern const char* tokenTypes[10];

enum TokenTypes {
     TOK_NO_TYPE,
     TOK_WORD,
     TOK_PLUS,
     TOK_MINUS,
     TOK_DIV,
     TOK_MUL,
     TOK_NUMBER,
     TOK_COLON,
     TOK_SEMICOLON,

     TOK_ANY, /*
		indicates any type, used by the 'parser' at codegen.
		no token should have this type.
	      */
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
  function pointer for 'getX', validate is a function pointer to
  functions like 'isdigit(int)' or 'isalpha(int)'.
*/
typedef int (*validate)(int);

/*
  those 'get' functions work by first creating a new view of the
  original text, then they get the size of that and strncpy it to
  the new char*. (which has to be manually free'd later)
*/
static inline char*
getX(const char* text, const char** view, validate f);

static char*
getWord(const char* text, const char** view);

static char*
getNum(const char* text, const char** view);

void
freeTokStream(TokStream* head);

/*
  creates a stream of tokens from a line of code.
*/
TokStream*
tokenize(const char* line);

#endif
