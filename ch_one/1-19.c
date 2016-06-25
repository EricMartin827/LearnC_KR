#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

#define LINE_LENGTH 10
#define NEWLINE '\n'
#define FAILURE -1
#define SUCCESS 0

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
        size_t lim = (*limit) - 1;

        for (ii = 0u; ((c = getchar()) != EOF) &&
                     (c != NEWLINE); ii++) {
                if (!(ii < lim) && (lim++, lim<<=1)) {
                        GROW(char, *ibuf, lim);
                        if (!(*ibuf)) {
                                perror("You require moe memory!");
                                return FAILURE;;
                        }
                } else if (!lim) {
                        errno = EOVERFLOW;
                        perror("You overflowed the limit!");
                        return FAILURE;
                }
                (*ibuf)[ii] = c;
        }
        if (c == NEWLINE)
                (*ibuf)[ii++] = c;
        (*ibuf)[ii] = '\0';
        return ii;
}

static void
rev_l(char **ibuf, size_t len)
{
        size_t ii = 0;
        size_t jj = (len > 2) ? (len - 2) : 0;
        
        while (jj > ii) {
                char temp = (*ibuf)[ii];
                (*ibuf)[ii++] = (*ibuf)[jj];
                (*ibuf)[jj--] = temp;
        }
}

int
main(void)
{
        int len;
        char *line = NULL;
        size_t lim = LINE_LENGTH;
        INIT(char, line, lim);
        if (!line) {
                perror("You require more memory!");
                return FAILURE;
        }
        while ((len = read_l(&line, &lim)) > 0) {
                rev_l(&line, len);
                fprintf(stdout, "%s", line);
        }
        if (len < 0)
                return FAILURE;
        free(line);
        
        return 0;
}
