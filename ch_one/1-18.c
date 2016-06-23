#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#define NEWLINE '\n'
#define BLANK ' '
#define TAB '\t'
#define LINE_LENGTH 10
#define SUCCESS 0
#define FAILURE -1

static int
readline(char **ibuf, uint32_t *limit)
{
	int c, k;
	uint32_t lim = *limit;
	uint32_t i = 0;
	char *temp;
		

	while ((c = getchar()) != EOF && c != NEWLINE) {
		if (i == lim) {
			lim<<=1;
			if (lim == 0) {
				errno = EOVERFLOW;
				return -1;
			}
			if ((temp = realloc(*ibuf, lim + 2)) == NULL) {
				return -1;
			}
			*ibuf = temp;
			*limit = lim;
		}
		printf("%c", c);
		(*ibuf)[i++] = c;
	}
	while ((i > 0) && (((k = (*ibuf)[i - 1]) == TAB) || (k == BLANK)))
		i--;

	if ((i != 0) && (c == NEWLINE)) {
		(*ibuf)[i++] = c;
		
	}
	(*ibuf)[i] = '\0';
	return i;
}

int
main(void)
{
	int len;
	uint32_t lim;
	int ret;
	char *in = NULL;
	char *out;
	lim = LINE_LENGTH;

	if ((line = malloc((LINE_LENGTH * sizeof(line[0])) + 2)) == NULL) {
		perror("mallic");
		ret = FAILURE;
		goto out;
	}
	
	while ((len = readline(&line, &lim)) != 0) {
		if (len < 0) {
			perror("failed to readline");
			ret = FAILURE;
			goto out;
		} else {
			fprintf(stdout, "%s", line);
		}
	}
	ret = SUCCESS;
out:
	if (line)
		free(line);
	return ret;
}
