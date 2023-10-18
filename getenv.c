#include"shell.h"







/**
 *get_environ - return array of string
 *Description: return array of string
 *@info:struct parameter
 *Return: 0
 */





char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);

		info->env_changed = 0;
	}

	return (info->environ);
}

