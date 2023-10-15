#include"shell.h"


/**
 *_memset - fill constant bytes of memory
 *Description:to fill constant bytes of memory
 *@s:pointer
 *@b:bytes
 *@n:bytes to be filled
 *Return:pointer
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int a;

	for (a = 0; a < n; a++)
		s[a] = b;

	return (s);
}



/**
 *ffree - free string
 *Description:free string of strings
 *@pp: string
 *Return: void
 */



void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;

	while (*pp)
		free(*pp++);
	free(a);
}





/**
 *_realloc - reallocate memory
 *Description:reallocate memory
 *@ptr :pointer
 *@old_size:old bytes
 *@new_size:new size
 *Return:pointer
 */



void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));

	if (!new_size)
		return (free(ptr), NULL);

	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);

	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;

	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];

	free(ptr);

	return (p);
}


