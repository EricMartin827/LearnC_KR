#include <stdio.h>
#include <string.h>
#include <limits.h>

int
main(void)
{
        int c;
        int max;
        int data[UCHAR_MAX];

        max = 0;
        memset(data, 0, sizeof(data));

        while ((c u= getchar()) != EOF) {
                data[c]++;
                max = (c > max) ? c : max;
        }

        for (c = 0; c < max; c++) {
                if (data[c] == 0)
                        continue;
                printf("\n%c: ", (char) c);
                int i = 0;
                while (i < data[c]) {
                        putchar('*');
                        i++;
                }
        }
        putchar('\n');
        return 0;
}
