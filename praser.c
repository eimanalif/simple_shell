#include"shell.h"




/**
 *find_path - find cmd in PATH
 *Description:find cmd
 *@info: structs
 *@pathstr:the PATH
 *@cmd:cmd to find
 *Return:path or NULL
 */



char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0;
	int curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);

	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}

	while (1)
	{

		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);

			if (!*path)
				_strcat(path, cmd);

			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}

			if (is_cmd(info, path))
				return (path);

			if (!pathstr[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}









/**
 *is_cmd - find excutable commands
 *Description: find excutable commands
 *@info: structs
 *@path:file path
 *Return: 1 or 0
 */



int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}





/**
 *dup_chars - duplicate characters
 *Description:duplicate char
 *@pathstr:pathstring
 *@start:start index
 *@stop:stop index
 *Return:pointer
 */



char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0;
int j = 0;

	for (j = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[j++] = pathstr[i];
	buf[j] = 0;
	return (buf);
}
