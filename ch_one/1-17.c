#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>

#define NEWLINE '\n'
#define SUCCESS 0
#define FAILURE -1
#define LINE_LENGTH 10
#define NUM_LINES 5
#define LINE_MARK 5

struct record {
        char **lines;
	uint32_t cnt;
        uint32_t cap;
};

static int
readline(char **ibuf, uint32_t *limit)
{
        int c;
	uint32_t i;
	uint32_t lim;
        char *temp;

	lim = *limit;
        for (i = 0; (c = getchar()) != EOF
                     && c != NEWLINE; i++) {
                if (i == lim - 2) {
                        lim<<=1;
                        if (lim == 0) {
                                errno = EOVERFLOW;
                                return -1;
                        }
                        if(!(temp = realloc(*ibuf, lim)))
                                return -1;
                        *limit = lim;
                        *ibuf = temp;
                }
                (*ibuf)[i] = c;
        }
        if (c == '\n')
                (*ibuf)[i++] = c;
        (*ibuf)[i] = '\0';
        return (int) i;
}

static int
addline(struct record *col, char *str)
{
	char **temp;
        if (col->cnt >= col->cap) {
                col->cap<<=1;
                if (col->cap == 0) {
                        errno = EOVERFLOW;
                        return FAILURE;
                }       
                if (!(temp = realloc(col->lines,
				     col->cap * sizeof(col->lines[0])))) {
                        return FAILURE;
                }
                col->lines = temp;
        }
        (col->lines)[col->cnt++] = strdup(str);
        return col->cnt;
}

static void
clean_up(struct record *col)
{
	unsigned i;
	if (col->lines) {
		while (col->lines[i]) {
			free(col->lines[i]);
			i++;
		}
	}
	free(col->lines);
}

static int
set_up(struct record *col, size_t capacity)
{
	col->cnt = 0;
	col->cap = capacity;
	col->lines = calloc(capacity, sizeof(col->lines[0]));
	if (!col->lines) {
		perror("calloc");
		return FAILURE;
	}
	return SUCCESS;
	
}

int 
main(void)
{
        struct record col;
        char *line;
	uint32_t lim;
        int len;
        int c, i;
	int ret;

	line = NULL;
	memset(&col, 0, sizeof(col));
	if ( (c = set_up(&col, NUM_LINES)) != 0 || (line = malloc(LINE_LENGTH)) == NULL) {
		ret = FAILURE;
		goto out;
	}

	lim = LINE_LENGTH;
	while ((len = readline(&line, &lim)) != 0) {
		if (len < 0) {
			ret = FAILURE;
			goto out;
		} else if (len > LINE_MARK) {
			if (addline(&col, line) < 0) {
				perror("Failed to add line");
				ret = FAILURE;
				goto out;
			}
		}
	}
	for (i = 0; i < col.cnt; i++)
		printf("%s", col.lines[i]);
out:
	if (line)
		free(line);
	else
		perror("malloc on line");
	clean_up(&col);
	return ret;
}
















