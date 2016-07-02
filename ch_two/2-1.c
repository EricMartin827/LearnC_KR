#include <stdio.h>

#define PRINT_SIZE(T) printf("Size of %s %ul\n", # T, sizeof(T))

int
main(void) {
        PRINT_SIZE(char);
        return 0;
}
