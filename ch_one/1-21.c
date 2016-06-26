#include <stdio.h>
#include <assert.h>

#define FAILURE -1
#define SUCCESS 0
#define SPACE ' '
#define TAB '\t'
#define TAB_S 4
#define BUF_CAP 10

static void
proc_s(char *buf, size_t limit)
{
        int c;
        size_t ii, jj;
        size_t wlim;

        assert(limit >= BUF_CAP);
        ii = jj = 0;
        wlim = (limit - TAB_S) + 1;
        while ((c = getchar()) != EOF) {
                if (c == SPACE && jj == 0 && ii >= wlim) {
                        buf[ii] = '\0';
                        ii = 0u;
                        fprintf(stdout, "%s", buf);
                }
                if (c == SPACE) {
                        jj++;
                        if (jj == TAB_S) {
                                ii -= (TAB_S - 1);
                                c  = TAB;
                                jj = 0u;
                        }
                } else {
                        jj = 0u;
                }
                buf[ii++] = c;
                
                if (ii == (limit - 1)) {
                        buf[ii] = '\0';
                        ii = 0u;
                        fprintf(stdout, "%s", buf);
                }
        }
        buf[ii] = '\0';
        fprintf(stdout, "%s", buf);
}

int
main(void)
{
        char buf[BUF_CAP];
        proc_s(buf, BUF_CAP);
        return 0;
}
