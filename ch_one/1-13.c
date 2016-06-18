#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BLANK ' '
#define TAB '\t'
#define NEWLINE '\n'
#define MAXLENGTH 1000

#define OUT 0
#define IN 1
#define NOT_LETTER(X) (X == BLANK) || (X == TAB) || (X == NEWLINE)


int
main(void)
{
        int c;
        int blen = 0;
        int len = 0;
        int data[MAXLENGTH];
        uint8_t state = OUT;

        memset(data, 0, sizeof(data));

        while ((c = getchar()) != EOF) {
                if (NOT_LETTER(c)) {
                        if (state == IN) {
                                data[len]++;
                        }
                        state = OUT;
                } else if (state == OUT) {
                        state = IN;
                }
                len = (state == IN) ? (len + 1) : 0;

                if (len < MAXLENGTH) {
                        blen = (len > blen) ? len : blen;
                } else {
                        data[len - 1]++;
                        while ((c = getchar()) != EOF
                               && !(NOT_LETTER(c)));
                }
        }

        /*Account for file not ending in NEWLINE*/
        if (len > 0)
                data[len]++;

        for (c = 0; c <= blen; c++) {
                if (data[c] == 0)
                        continue;
                printf("\nLength %d: ", c);
                int i = 0;
                while (i < data[c]) {
                        putchar('*');
                        i++;
                }
        }
        putchar('\n');
        return 0;
}
