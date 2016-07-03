#include <stdio.h>
#include <stdlib.h>

#define COLUMN 10
#define BUF_CAP 300
#define TAB '\t'
#define SPACE ' '
#define NEWLINE '\n'

static inline unsigned
read_l(char *buf, size_t lim) {

        int c;
        size_t ii;

        for (ii = 0u; (ii < lim - 1) &&
                     ((c = getchar()) != EOF) &&
                     (c != NEWLINE); ii++) {
                buf[ii] = c;
        }
        if (c == NEWLINE)
                buf[ii++] = c;
        buf[ii] = '\0';
        return ii;
}

static void
wrap(char *buf, unsigned col, unsigned endpt)
{
        unsigned  ii, jj;
        int c;

        ii = jj = 0u;
        c = buf[ii++];
        while (ii < endpt - 1) {
                while (ii < endpt - 1 && jj < col) {
                        putchar(c);
                        c = buf[ii++];
                        jj++;
                }
                while (ii < endpt - 1 && c != SPACE && c != TAB) {
                        putchar(c);
                        c = buf[ii++];
                }
                putchar(c);
                c = buf[ii++];
                putchar(NEWLINE);
                jj = 0u;
        }
        putchar(NEWLINE);
        putchar('\0');
                
}

int
main(void)
{
        unsigned len;
        static char line[BUF_CAP];        
        while ((len = read_l(line, BUF_CAP)) > 0) {
                if (len < COLUMN) {
                        printf("%s\n", line);
                        continue;
                } else {
                        wrap(line, COLUMN, len);
                }
        }
        return 0;
}
