#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define FAILURE -1
#define SUCCESS 0
#define TAB '\t'
#define TAB_SPACE 4
#define SPACE ' '
#define NEWLINE '\n'
#define OFFSET (TAB_SPACE + 1)
#define LINE_DEFAULT 10

#define INIT(T, A, S) ({                                          \
                        const T *_A = (A);                        \
                        const size_t _S = (S);                    \
                        A = malloc(_S * sizeof(_A[0])); })

#define GROW(T, A, S) ({                                                \
                        T *_A = (A);                                    \
                        const size_t _S = (S);                          \
                        _A = realloc(A, _S) ;                           \
                        (_A) ? (A = _A) : (free(A), A = NULL);})

static int
read_l(char **ibuf, size_t *limit)
{
        int c;
        size_t ii;
        size_t lim = (ii = *limit, ii > (OFFSET))
                ? (ii - OFFSET)
                : (LINE_DEFAULT - OFFSET);

        for (ii = 0u; ((c = getchar()) != EOF) &&
                     (c != NEWLINE); ii++) {
                if (!(ii < lim) && (lim++, lim<<=1)) {
                        GROW(char, *ibuf, lim);
                        if (!(*ibuf)) {
                                perror("You require more memory!");
                                return FAILURE;;
                        }
                } else if (!lim) {
                        errno = EOVERFLOW;
                        perror("You overflowed the limit!");
                        return FAILURE;
                }
                if (c == TAB) {
                        size_t jj;
                        for (jj = 0u; jj < TAB_SPACE; jj++)
                                (*ibuf)[ii++] = SPACE;
                } else {
                        (*ibuf)[ii] = c;
                }
        }
        if (c == NEWLINE)
                (*ibuf)[ii++] = c;
        (*ibuf)[ii] = '\0';
        return ii;
}

int
main(void)
{
        int len;
        char *line = NULL;
        size_t limit = LINE_DEFAULT;
        INIT(char, line, LINE_DEFAULT);
        if (!line) {
                perror("You Require More Memory!");
                return FAILURE;
        }
        while ((len = read_l(&line, &limit)) > 0)
                fprintf(stdout, "%s", line);
        
        return (len == 0) ? (free(line), SUCCESS) : FAILURE;
}
