#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

static inline float
fahr2cel(float fahr)
{
        return (5.0 / 9.0) * (fahr - 32.0);
}

int
main(void)
{
        float fahr = UPPER;
        
        puts("Fahrenheit\t\tCelsius");
        for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
                printf(" %6.1f\t\t\t%6.1f\n", fahr,
                       fahr2cel(fahr));
        }
        return 0;
}
