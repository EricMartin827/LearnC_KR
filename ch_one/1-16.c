#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define NEWLINE '\n'
#define SUCCESS 0
#define FAILURE 1
#define INITIAL_CAP 50

static int
readline(char **ibuf, int limit, int *save)
{
        int c, i;
        char *temp;
        for (i = 0; i < limit - 1
                     && (c = getchar()) != EOF
                     && c != NEWLINE; i++) {
                if (i == limit - 2) {
                        limit<<=1;
                        if(!(temp = realloc(*ibuf, limit)))
                                return -1;
                        *save = limit;
                        *ibuf = temp;
                }
                (*ibuf)[i] = c; 
        }
        if (c == '\n')
                (*ibuf)[i++] = c;
        (*ibuf)[i] = '\0';
        return i;
}

static void
copy(char *to, char *from)
{
        int i = 0;
        while ((to[i] = from[i]) != '\0')
                i++;
}

int
main(void)
{
        int len;
        int max;
        int limit;
        int save;
        int ret;
        char *line = NULL;
        char *longest = NULL;
        char *temp = NULL;

        max = 0;
        ret = SUCCESS;
        limit = INITIAL_CAP;
        longest = (line = malloc(INITIAL_CAP)) ? malloc(INITIAL_CAP) : NULL;

        if (!longest && !line) {
                ret = FAILURE;
                goto out;
        }

        while ((len = readline(&line, limit, &save)) != 0) {
                if (len < 0) { 
                        ret = FAILURE;
                        goto out;
                } else if (len > limit) {
                        if (!(temp = realloc(longest, save))) {
                                ret = FAILURE;
                                goto out;
                        }
                        longest = temp;
                        limit = save;
                } 
                if (len > max) {
                        max = len;
                        copy(longest, line);
                }
        }
        ret = SUCCESS;
out:
        if (max > 0) {
                printf("\nlongest line:\n%s\nlength = %d\n",
                       longest, max);
        }
        free(line);
        free(longest);
        return ret;
}
