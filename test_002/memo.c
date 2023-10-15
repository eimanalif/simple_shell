#include"shell.h"





/**
 *bfree - free pointer to NULL
 *Description:free pointer
 *@ptr:adrees of pointer
 *Return: 1 or 0
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

