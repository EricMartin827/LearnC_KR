#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define MODULO '%'

static void
minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != MODULO) {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case '\0':
			--p;
			break;
		case 'd':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 's':
			for (sval = va_arg(ap, char*); *sval; sval++)
				putchar(*sval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}

int
main(void)
{
	
	minprintf("What a lovely day %s %d %f %s\n", "Weeeee", 10, 10.0, "Weeeee");
	printf("%d%s", 5, "Hooral\n");
	printf("G = %g, E = %e\n", 4349203480.0, 4349203480.0);
	long double x = 6.7;
	printf("%Lf\n", x);
	minprintf("%\0bug!bug!bug!\n");
	printf("%-100000d\n", 5);
	return EXIT_SUCCESS;

}
