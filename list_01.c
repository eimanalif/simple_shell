#include "shell.h"





/**
 *print_list - print elements of linked list
 *Description:print elements of linked list
 *@h:head pointer
 *Return:size of list
 */




size_t print_list(const list_t *h)
{
	size_t j = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");

		h = h->next;

		j++;
	}

	return (j);
}





/**
 *node_starts_with - return node with certain string
 *Description: return node with certain string
 *@node:pointer to head
 *@prefix:string
 *@c:charcter to match
 *Return:node or NULL
 */


list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *i = NULL;

	while (node)
	{
		i = starts_with(node->str, prefix);

		if (i && ((c == -1) || (*i == c)))
			return (node);

		node = node->next;
	}

	return (NULL);
}









/**
 *list_len - find length of a linked list
 *Description:find length
 *@h: head node
 *Return:list size
 */


size_t list_len(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		h = h->next;
		a++;
	}

	return (a);
}







/**
 *get_node_index - get nodes index
 *Description:get node index
 *@head:pointer to head
 *@node:pointer to nodes
 *Return: index or -1
 */


ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t a = 0;

	while (head)
	{
		if (head == node)
			return (a);

		head = head->next;
		a++;
	}

	return (-1);
}






/**
 *list_to_strings - return str of node
 *Desscription:return str of a node
 *@head:head pointer
 *Return:string array
 */



char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head);
	size_t k;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);

	strs = malloc(sizeof(char *) * (i + 1));

	if (!strs)
		return (NULL);

	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);

		if (!str)
		{
			for (k = 0; k < i; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}

	strs[i] = NULL;

	return (strs);
}


