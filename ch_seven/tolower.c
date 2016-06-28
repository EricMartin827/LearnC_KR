#include <stdio.h>
/* #include <ctype.h> */


#define tolower(C) ({					\
			const char _C = (C);		\
			((_C >= 'A') && (_C <= 'Z')) ?	\
				(_C + 32) : (_C); })

int
main(void)
{
	int c;
	while ((c = getchar()) != EOF) {
		putchar(tolower(c));
	}
	return 0;
}
