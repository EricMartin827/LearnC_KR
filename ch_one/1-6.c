#include <stdio.h>
#include <string.h>

#define CAPACITY 51

static char text[CAPACITY - 1];

int
main(void)
{
        int bool;
        memcpy(text, "The Value of EOF != getchar() : ",
               CAPACITY);
        
        while ((bool = (EOF != getchar())) != 0)
                printf("%s%d\n", text, bool);
        printf("%s%d\n", text, bool);
        
        return 0;
}
