#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#define LOWER "tolower"
#define UPPER "toupper"
#define FUNC(A) (A)

int
main(int argc, char **argv)
{
	int c;
	char cmd[8];
	//int (*func)(char c);
	if (argc != 1) {
		errno = EPROTO;
		perror("no arguments.");
		return EXIT_FAILURE;
	}
	strncpy(cmd, argv[0], sizeof(cmd));
	if ((!cmd[0]) &&
	    (((c = strcmp(cmd, LOWER)) != 0)) ||
	    (strcmp(cmd, UPPER) != 0))) {
		errno = EINVAL;
		perror("argv[0] = tolower or toupper");
		return EXIT_FAILURE;
	}
	int (*func)(int c) = (c == 0) ? tolower : toupper;
	while ((c = getchar()) != EOF) {
		putchar(func(c));
	}
	return EXIT_SUCCESS;
}
