#include <stdio.h>
#include <stdint.h>

#define SPACE ' '
#define TAB '\t'
#define NEWLINE '\n'

#define OUT 0
#define IN 1

int
main(void)
{
        int c;
        
        uint8_t state = OUT;
        size_t ch = 0;
        size_t words = 0;
        size_t newlines = 0;
        
        while ((c = getchar()) != EOF) {
                
                ch++;
                if (c == NEWLINE)
                        newlines++;
                if (c == NEWLINE || c == TAB || c == SPACE) {
                        state = OUT;
                }
                else if (state == OUT) {
                        state = IN;
                        words++;
                }
        }
        printf("\nResults:\n"
               "Total Characters : %lu\n"
               "Total Words : %lu\n"
               "Total Newlines : %lu\n",
               ch, words, newlines);
        return 0;
}
