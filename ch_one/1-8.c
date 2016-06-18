#include <stdio.h>

#define BLANK ' '
#define TAB '\t'
#define NEWLINE '\n'

int
main(void)
{
        int c;
        size_t total = 0;
        size_t blanks = 0;
        size_t tabs = 0;
        size_t newlines = 0;
        
        while ((c = getchar()) != EOF) {
                switch (c) {
                case BLANK:
                        blanks++;
                        break;
                case TAB:
                        tabs++;
                        break;
                case NEWLINE:
                        newlines++;
                }
                total++;
        }
        printf("Results:\n"
               "Count = %lu\nBlanks = %lu\n"
               "Tabs = %lu\nNewlines = %lu\n",
               total, blanks, tabs, newlines);
        return 0;
}
