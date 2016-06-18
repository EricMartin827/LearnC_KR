#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define BLANK ' '
#define TAB '\t'
#define NEWLINE '\n'

#define OUT 0
#define IN 1
#define NOT_LETTER(X) (X == BLANK) || (X == TAB) || (X == NEWLINE)

int
main(void)
{
        int c;
        int state = OUT;

        while ((c = getchar()) != EOF) {
                if (NOT_LETTER(c)) {
                        if (state == IN) {
                                fputc(NEWLINE, stdout);
                                fflush(stdout);
                        }
                        state = OUT;
                } else if (state == OUT) {
                        state = IN;
                }
                if (state == IN) {
                        fputc(c, stdout);
                }
        }
        return 0;
}
