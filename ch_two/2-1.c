#include <stdio.h>
#include <limits.h>
#include <float.h>

#define PRINT_SIZE(T) printf("Size of %s: %lu bytes\n", # T, sizeof(T))

#define PRINT_MIN(X, F) ({                                              \
                X _X = ~0x0;                                            \
                _X = (_X > 0)                                           \
                        ? 0                                             \
                        : (_X & (0x1 << ((sizeof(X) << 3) - 1)));       \
                char *msg = "Minimum Value of %s : %" # F "\n";         \
                        printf(msg, # X, _X); })

#define PRINT_MAX(X, F) ({                                              \
                X _X = ~0x0;                                            \
                _X = (_X > 0)                                           \
                        ? _X                                            \
                        : (_X & ~(0x1 << ((sizeof(X) << 3) - 1)));      \
                char *msg = "Maximum Value of %s : %" # F "\n";       \
                        printf(msg, # X, _X); })

#define L_PRINT_MIN(X, F) ({                                            \
                X _X = ~0x0;                                            \
                _X = (_X > 0L)                                          \
                        ? 0                                             \
                        : (_X & (0x1L << ((sizeof(X) << 3) - 1)));      \
                char *msg = "Minimum Value of %s : %" # F "\n";         \
                        printf(msg, # X, _X); })

#define L_PRINT_MAX(X, F) ({                                            \
                X _X = ~0x0;                                            \
                _X = (_X > 0L)                                          \
                        ? _X                                            \
                        : (_X & ~(0x1L << ((sizeof(X) << 3) - 1)));     \
                char *msg = "Maximum Value of %s : %" # F "\n";         \
                        printf(msg, # X, _X); })

#define PRINT_FB(F) ({                                              \
                        char *msg = "Minimum Double: %" # F "\n";   \
                        printf(msg, FLT_MIN);                       \
                        msg = "Maximum Double: %" #F "\n";          \
                        printf(msg, FLT_MAX); })

int
main(void) {

        PRINT_SIZE(char);
        PRINT_MIN(char, d);
        PRINT_MAX(char, d);

        PRINT_SIZE(unsigned char);
        PRINT_MIN(unsigned char, u);
        PRINT_MAX(unsigned char, u);

        PRINT_SIZE(short);
        PRINT_MIN(short, d);
        PRINT_MAX(short, d);

        PRINT_SIZE(unsigned short);
        PRINT_MIN(unsigned short, u);
        PRINT_MAX(unsigned short, u);

        PRINT_SIZE(int);
        PRINT_MIN(int, d);
        PRINT_MAX(int, d);

        PRINT_SIZE(unsigned int);
        PRINT_MIN(unsigned int, u);
        PRINT_MAX(unsigned int, u);

        PRINT_SIZE(long);
        L_PRINT_MIN(long, ld);
        L_PRINT_MAX(long, ld);
        L_PRINT_MIN(long, lx);
        L_PRINT_MAX(long, lx);

        PRINT_SIZE(unsigned long);
        L_PRINT_MIN(unsigned long, lu);
        L_PRINT_MAX(unsigned long, lu);
        L_PRINT_MIN(unsigned long, lx);;
        L_PRINT_MAX(unsigned long, lx);

        PRINT_SIZE(float);        
        PRINT_SIZE(double);
        PRINT_SIZE(long double);
        PRINT_FB(e);

        return 0;
}
