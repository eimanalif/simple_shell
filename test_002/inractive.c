#include"shell.h"



/**
 *interactive -  check shell is interactive
 *Description:check if shell is interactive
 *@info:strct adress
 *Return:1 or 0
 */


int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
