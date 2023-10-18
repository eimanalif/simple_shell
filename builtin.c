#include "shell.h"




/**
 *_myhelp - changes the current directory of the process
 *Description:changes the current directory of the process
 *@info:struct parameter
 *Return:0
 */


int _myhelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr); /* temp att_unused workaround */
	return (0);
}



/**
 *_myhistory - disply command history
 *Description:disply commands each one by line
 *@info: struct
 *Return: 0
 */


int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

