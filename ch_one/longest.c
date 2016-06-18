#include <stdio.h>

#define NEWLINE '\n'
#define MAXLINE 1000

static int
readline(char *buf, int limit)
{
        int c, i;

        for (i = 0; (i < limit - 1)
                     && ((c = getchar()) != EOF)
                     && (c != NEWLINE); i++) {
                buf[i] = c;
        }
        if (c == '\n') {
                buf[i] = c;
                i++;
        }
        buf[i] = '\0';
        return i;
}

static void
copy(char *to, char *from)
{
        int i = 0;
        while((to[i] = from[i]) != '\0')
                i++;
}

int
main(void)
{
        int len;
        int max;
        char line[MAXLINE];
        char longest[MAXLINE];

        max = 0;
        while (((len = readline(line, MAXLINE)) > 0)) {
                if (len > max) {
                        max = len;
                        copy(longest, line);
                }
        }
        if (max > 0)
                printf("\nlongest line:\n%s\nlength = %d\n",
                       longest, max);
        return 0;
}
