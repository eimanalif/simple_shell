#include "shell.h"





char *read_line(void);


/**
 *main - main function for simple shell
 *Description:main function for for simple shell
 *@argc:argument count
 *@argv:argument vector
 *Return: 0 (success)
 */



int main(int argc, char **argv)
{
	char *line = NULL;
	/*char **command = NULL;*/
	int stat = 0;
	(void) argc;
	(void) argv;

	while (1)
	{
		line = read_line();
		if (line == NULL)	/**EOF**/
			return (stat);
	printf("%s\n", line);
		/*command = tokn(str);*/
	/*	stat = _excut(command, argv);*/
	
	}
}
