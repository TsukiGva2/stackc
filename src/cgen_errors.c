#include <cgen_errors.h>

void
unexpectedTokenError(int expected, int got) {
     fprintf(stderr, "ERROR: expected '%s', got '%s'\n",
	     tokenTypes[expected], tokenTypes[got]);
}

void
unrecognizedTokenError(int got) {
     fprintf(stderr, "ERROR: unrecognized token type: '%s'\n",
	     tokenTypes[got]);
}

void
wrongContextError(int got, const char* context) {
     fprintf(stderr, "ERROR: token '%s' should only be used on %s\n",
	     tokenTypes[got], context);
}
