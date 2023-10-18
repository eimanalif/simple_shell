#include"shell.h"





/**
 *input_buf - command buffer
 *Description:command buffer
 *@info:parameter struct
 *@buf:buffer adress
 *@len:len var adress
 *Return:bytes
 */



ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t i = 0;
	size_t len_p = 0;

	if (!*len)
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		i = getline(buf, &len_p, stdin);
#else
		i = _getline(info, buf, &len_p);
#endif

		if (i > 0)
		{

			if ((*buf)[i - 1] == '\n')
			{
				(*buf)[i - 1] = '\0';
				i--;
			}

			info->linecount_flag = 1;
			remove_comments(*buf);

			build_history_list(info, *buf, info->histcount++);

			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = i;
				info->cmd_buf = buf;
			}
		}
	}
	return (i);
}








/**
 *get_input - gets line
 *Description:get a line minus new line
 *@info:struct parameter
 *Return: bytes
 */


ssize_t get_input(info_t *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t k, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);

	if (r == -1) /* EOF */
		return (-1);

	if (len) /* we have commands left in the chain buffer */
	{
		j = k; /* init new iterator to current buf position */
		p = buf + k; /* get pointer for return */

		check_chain(info, buf, &j, k, len);

		while (j < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		k = j + 1; /* increment past nulled ';'' */

		if (k >= len)
		{
			k = len = 0; /* reset position and length */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back pointer to current command position */
		return (_strlen(p)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */

	return (r); /* return length of buffer from _getline() */
}








/**
 *read_buf - read buffer
 *Description:read buffer
 *@info:parameter struct
 *@buf:buffer
 *@i:size
 *Return:size of buffer
 */



ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t j = 0;

	if (*i)
		return (0);

	j = read(info->readfd, buf, READ_BUF_SIZE);

	if (j >= 0)
		*i = j;

	return (j);
}






/**
 *_getline - get nxt line from STDIN
 *Description:get next line in STDIN
 *@info:parametr struct
 *@ptr:pointer
 *@length:size of buffer
 *Return:size
 */





int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t j;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;

	if (p && length)
		s = *length;

	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);

	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	j = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + j : j + 1);

	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);
	if (s)
		_strncat(new_p, buf + i, j - i);

	else
		_strncpy(new_p, buf + i, j - i + 1);

	s += j - i;
	i = j;
	p = new_p;

	if (length)
		*length = s;

	*ptr = p;
	return (s);
}








/**
 *sigintHandler - ctrl-C
 *Description:ctrl-C
 *@sig_num:signal num
 *Return: void
 */


void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}


































