#include"shell.h"








/**
 *remove_comments - a functions to replace '#' with '\0'
 *Description:function to replace '#' with'\0'
 *@buf:adress of str
 *Return:0
 */




void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)


		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}
