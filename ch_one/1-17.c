#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define NEWLINE '\n'
#define SUCCESS 0
#define FAILURE 1
#define LINE_LENGTH 100;
#define NUM_LINES 100
#define LINE_MARK 80

struct record {
        char **lines;
        int capacity;
};

static int
readline(char **ibuf, int limit, int *save)
{
        int c, i;
        char *temp;
        for (i = 0; (c = getchar()) != EOF
                     && c != NEWLINE; i++) {
                if (i == limit - 2) {
                        limit<<=1;
                        if (limit == 0) {
                                errno = EOVERFLOW;
                                return -1;
                        }
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

static int
addline(struct record *r, int index, char *str)
{
        char **temp;
        char *rem;
        if (index >= r->capacity) {
                r->capacity<<=1;
                if (r->capacity == 0) {
                        errno = EOVERFLOW;
                        return -1;
                }       
                if (!(temp = realloc(r->lines, r->capacity))) {
                        return -1;
                }
                r->lines = temp;
        }
        (r->lines)[index++] = str;
        return index;
}

int 
main(void)
{
        struct record col;
        char line;
        int len;
        int lim = LINE_LENGTH;
        int sav;
        int c, i;
        
        col.lines = malloc(NUM_LINES * lines[0]);
        col.capacity = NUM_LINES;

        while ((len = readline(&col, lim, &sav)) != 0) {
                if (len < 0) {
                        perror("failed to add line");
                        goto out;
                }
        }
out:
}
















