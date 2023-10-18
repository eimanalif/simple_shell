#include "shell.h"




/**
 *_mysetenv - intial new environment or modify exist
 *Description:intial new or modify old
 *@info:struct parameter
 *Return: 0
 */


int _mysetenv(info_t *info)
{
        if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}

	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);

	return (1);
}






/**
 *_myunsetenv - remove environment
 *Description:remove environment
 *@info:struct parameter
 *Return: 0
 */



int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}

	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}







/**
 *populate_env_list - populate environment linked list
 *Description:populate environment linked list
 *@info:struct parameter
 *Return: 0
 */




int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t j;

	for (j = 0; environ[j]; j++)
		add_node_end(&node, environ[j], 0);

	info->env = node;

	return (0);
}




/**
 *_getenv - get value of env variable
 *Description:gets variables
 *@info:struct parameter
 *@name:env variable name
 *Return: var
 */






char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);

		if (p && *p)
			return (p);
		node = node->next;
	}

	return (NULL);
}




/**
 *_myenv - print environment
 *Description:print environment
 *@info:struct parameter
 *Return: 0
 */



int _myenv(info_t *info)
{
	print_list_str(info->env);

	return (0);
}

