#include"shell.h"



/**
 *interactive -  checks shell is interactives
 *Description:checks if shell is interactives
 *@info:strct adress
 *Return:1 or 0
 */


int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
