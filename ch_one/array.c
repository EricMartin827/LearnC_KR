#include <stdio.h>

#define SPACE ' '
#define isnum(X) (X >= '0') && (X <= '9')

/* count digits, white space, and others*/
int
main(void)
{
        int c, i, nwhite, nother;
        int ndigit[10];

        nwhite = nother = 0;
        for (i = 0; i < 10; i++)
                ndigit[i] = 0;

        while ((c = getchar()) != EOF) {
                if (isnum(c)) {
                        ndigit[(c - '0')]++;
                } else if (c == SPACE) {
                        nwhite++;
                } else {
                        nother++;
                }
        }
        printf("\ndigits:\n");
        for (i = 0; i < 10; i++)
                printf("%d  = %d\n", i, ndigit[i]);
        printf("\nwhite space = %d, other = %d\n", nwhite, nother);
        return 0;
}
