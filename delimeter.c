#include"shell.h"



/**
 *is_delim - checks if char is delimeter
 *@c:char to check
 *@delim: delimeter string
 *Return: 1 or 0
 */


int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
