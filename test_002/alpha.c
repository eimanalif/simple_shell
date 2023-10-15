#include "shell.h"


/**
 *_isalpha - checks alphabetic charter
 *Description:checks alphapatic characters
 *@c:char
 *Return:1 or 0
 */



int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
