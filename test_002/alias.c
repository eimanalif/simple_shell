#include "shell.h"




/**
 *unset_alias - unset alias
 *Description:unset alias or remove it
 *@info:struct parameters
 *@str:string
 *Return: 0 or 1
 */

int unset_alias(info_t *info, char *str)
{
	char *p, s;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	s  = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = s;
	return (ret);
}





/**
 *set_alias - sets alias
 *Description:set a string to alias
 *@info:struct parameters
 *@str: string alias
 *Return: 0 or 1
 */




int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}








/**
 *print_alias - alias string prints
 *Description:alias string prints
 *@node:alias node
 *Return:0 or 1
 */



int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}






/**
 *_myalias - works same like builtin alias
 *Description:same like builtin alias
 *@info:struct parameters
 *Return: 0
 */



int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
