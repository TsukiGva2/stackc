#ifndef CGEN_ERRORS_H
#define CGEN_ERRORS_H

/*#include <common.h>*/
#include <lex.h>

void
unexpectedTokenError(int expected, int got);

void
unrecognizedTokenError(int got);

#endif
