#include <stdio.h>

/**
 * main - print the environments
 *
 * @ac:the arguments count
 * @av:array of string
 * @env:linked list local copy
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
	unsigned int i;
i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
