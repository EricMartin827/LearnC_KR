#include <stdio.h>

#define LOWER -20
#define UPPER 150
#define STEP 11

static inline float
cel2fah(float cel)
{
        return (9.0 / 5.0) * cel + 32.0; 
}

int
main(void)
{
        float celsius = LOWER;
        
        puts("Celsius\t\t\tFahrenheit");
        while (celsius <= UPPER) {
                printf("%6.1f\t\t\t  %6.1f\n", celsius,
                       cel2fah(celsius));
                celsius += STEP;
        }
        return 0;
}
