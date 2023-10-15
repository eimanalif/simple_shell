#include "shell.h"


/**
 *read_line - to read the input line
 *Description:to read input from user
 *Return:char
 */


char *raed_line(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t n;

	write(STDOUT_FILENO, "$ ", 2);

	n = getline(&line, &length, stdin);
	if (n == -1)
	{
		free(line);

		return (NULL);
	}
	return (line);
}
