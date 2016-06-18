#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#define BLANK ' '
#define TAB '\t'

enum boolean {
        FALSE,
        TRUE
};

int
main(void)
{
        printf("Standard Input is Terminal : %d\n",
               isatty(fileno(stdin)));
        printf("Standard Output is Terminal : %d\n",
               isatty(fileno(stdout)));
        
        int c = getchar();
        int found_blank = FALSE;

        while (c != EOF) {
                c =  (c == TAB) ? BLANK : c;
                found_blank = (c == BLANK);
                putchar(c);
                c = getchar();
                while (found_blank && (c == TAB || c == BLANK))
                        c = getchar();
        }
        return 0;
}
