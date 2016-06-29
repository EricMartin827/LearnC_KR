#include <stdarg.h>

#define CONV_SIG '%'

static void
minprintf(char *fmt, ...)p
{
	va_list ap;
	char *p;

	va_start(ap, fmr);
	for (p = fmt; *p; p++) {
		if (p != CONV_SIG) {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case 'd':
		case 'p':
			case ''
		}
	}
	
}
