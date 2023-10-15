#include "shell.h"






/**
 *build_history_list - start history linked list
 *Description:start history
 *@info:struct parameter
 *@buf:buffer
 *@linecount:history linecount
 *Return:always 0
 */


int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}






/**
 *get_history_file - get history
 *Description:get history
 *@info: struct parameter
 *Return:str
 */



char *get_history_file(info_t *info)
{
	char *buff;
	char *dir;

	dir = _getenv(info, "HOME=");

	if (!dir)
		return (NULL);

	buff = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));

	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dir);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);

	return (buff);
}





/**
 *write_history -  create or append file
 *Description: create or append file
 *@info:struct parameter
 *Return: 1 or -1
 */


int write_history(info_t *info)
{
	ssize_t fd;
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);

	if (fd == -1)
		return (-1);

	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}

	_putfd(BUF_FLUSH, fd);
	close(fd);

	return (1);
}






/**
 *read_history - read history file
 *Description: read history file
 *@info: struct parametr
 *Return:int
 */





int read_history(info_t *info)
{
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buff = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (fsize + 1));
	if (!buff)
		return (0);
	rdlen = read(fd, buff, fsize);
	buff[fsize] = 0;
	if (rdlen <= 0)
		return (free(buff), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buff[i] == '\n')
		{
			buff[i] = 0;
			build_history_list(info, buff + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buff + last, linecount++);
	free(buff);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);

	return (info->histcount);
}








/**
 *renumber_history - renumbered linked lists
 *Description:renumber linked list
 *@info:struct parameter
 *Return:int
 */





int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int j = 0;

	while (node)
	{
		node->num = j++;
		node = node->next;
	}

	return (info->histcount = j);
}

