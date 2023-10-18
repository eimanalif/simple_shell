#include"shell.h"


/**
 *_setenv - Initialize a new environment variables,
 *		or modify an existing one
 *Description:Initialize a new environment variables,
 *		or modify an existing one
 *@info:struct parameter
 *@var:env var
 *@value: env var values
 *Return: 0
 */



int _setenv(info_t *info, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buff = malloc(_strlen(var) + _strlen(value) + 2);

	if (!buff)
		return (1);

	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	node = info->env;

	while (node)
	{
		p = starts_with(node->str, var);

		if (p && *p == '=')
		{
			free(node->str);
			node->str = buff;
			info->env_changed = 1;
			return (0);
		}

		node = node->next;
	}
	add_node_end(&(info->env), buff, 0);
	free(buff);
	info->env_changed = 1;

	return (0);
}









/**
 *_unsetenv - remove an environment variables
 *Description: remove an env var
 *@info: struct parameter
 *@var:env var
 *Return: 1 or 0
 */



int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t j = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);

		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), j);
			j = 0;
			node = info->env;
			continue;
		}

		node = node->next;
		j++;
	}

	return (info->env_changed);
}

