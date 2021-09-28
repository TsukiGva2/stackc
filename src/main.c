#include <common.h>
#include <language.h>

#define BUF_SIZE 512 /* 512 chars per line */

#define READ_LINE(buf, size)\
     if (!fgets(buf, size, stdin) && ferror(stdin)) {\
	  fprintf(stderr, "error getting line of input\n");\
	  return 1;\
     } else if (feof(stdin)) {\
	  printf("got ^D (EOF), exiting...\n");\
	  return 0;\
     }

int
main(void) { /* TODO: no cmdline args yet */
     char input[BUF_SIZE];

     for (;;) {
	  memset(input, 0, BUF_SIZE);
	  READ_LINE(input, BUF_SIZE);
#ifdef DEBUG
	  printf("%s\n", input);
#endif
	  fdumpc(input, stdout);
     }
     
     return 0;
}
