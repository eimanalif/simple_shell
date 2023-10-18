#include"shell.h"





/**
 *print_error - prints errors
 *Description:prints errors
 *@info:struct parameter
 *@estr:error type string
 *Return:0 or -1
 */



void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");

	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}






/**
 *print_d - prints decimal
 *Description:print integer on base 10
 *@input:input
 *@fd:filedescriptor
 *Return:int
 */



int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i;
	int count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;

	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;

	for (i = 1000000000; i > 1; i /= 10)
	{

		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}






/**
 *_erratoi - convert str to int
 *Description:convert string to integer
 *@s:string
 *Return:int
 */




int _erratoi(char *s)
{
	int i = 0;
	unsigned long int result = 0;

	if (*s == '+')
		s++;  /* TODO: why does this make main return 255? */


	for (i = 0;  s[i] != '\0'; i++)
	{

		if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10;
			result += (s[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}

		else
			return (-1);
	}

	return (result);
}







