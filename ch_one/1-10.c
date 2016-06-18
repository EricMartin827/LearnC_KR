#include <stdio.h>

#define TAB '\t'
#define BACKSPACE '\b'
#define BACKSLASH '\\'

int
main(void)
{
        int c = getchar();
        while (c != EOF) {
                switch (c) {
                case TAB:
                        fputs("\\t", stdout);
                        break;
                case BACKSPACE:
                        fputs("\\b", stdout);
                        break;
                case BACKSLASH:
                        fputs("\\\\", stdout);
                        break;
                default:
                        putchar(c);
                }
                c = getchar();
        }
        return 0;
}
