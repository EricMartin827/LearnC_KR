#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 100
#define NEWLINE '\n'

static int
readline(char *buf, size_t limit)
{
	int c;
	size_t ii;
	for (ii = 0u; ii < limit - 1 &&
		     (c = getchar()) != EOF &&
		     c != NEWLINE; ii++) {
		buf[ii] = c;
	}
	if (c == NEWLINE)
		buf[ii++] = c;
	buf[ii] = '\0';
	return ii;
}

static void
print_it(const char *line)
{
	char c;
	size_t ii = 0u;
	while ((c = line[ii++])) {
		if (isprint(c))
			printf("%c", c);
		else
			printf("%x", c);
		
	}
}

int
main(void)
{
	static char line[MAXLINE];
	while (readline(line, MAXLINE) > 0) {
		print_it(line);
	}
	return EXIT_SUCCESS;
}
