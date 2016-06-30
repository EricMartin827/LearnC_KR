#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <ctype.h>

#define MODULO '%'
#define MINUS '-'
#define PERIOD '.'
#define LONG 'l'
#define USIGNED 'u'
#define ADDRESS 'p'
#define DLONG 'L'

#define IS_HEX(C) (((A) == 'x') | ((A) == 'X'))
#define IS_OCT(C) (((A) == 'o') | ((A) == 'O'))

static void
minprintf(char *fmt, ...)
{
	va_list ap;
	char *p, *sval;
	int ival;
	short sh_val;
	long lval;
	float fval;
	double dval;
	long double ld_val;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != MODULO) {
			putchar(*p);
			continue;
		}
		switch (*++p) {
		case '\0':
			p--;
			break;
		case '-':
		case 's':
			
		}
	}
}


