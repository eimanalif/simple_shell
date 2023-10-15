#include"shell.h"



/**
 *_puts - print input
 *Description:print input
 *@str:string
 *Return: void
 */


void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}




/**
 *_putchar - write character
 *Description: write character
 *@c:character
 *Return:integer
 */


int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}





/**
 *starts_with - check substring
 *Descrition:checks if needle starts with haystack
 *@haystack:string to lookfor
 *@needle:substring
 *Return: adress or NULL
*/



char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}


