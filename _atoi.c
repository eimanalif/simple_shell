#include"shell.h"


/**
 *_atoi - converts string to integer
 *Description:convert str to int
 *@s:string
 *Return:0
 */

int _atoi(char *s)
{
	int i;
	int sign = 1;
	int flag = 0;
	int output;
	unsigned int result = 0;


	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}


	if (sign == -1)
		output = -result;

	else
		output = result;

	return (output);
}

