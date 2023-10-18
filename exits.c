#include"shell.h"


/**
 **_strncat - concatenate strings
 *Description: concatenates strings for n number of chars
 *@dest:string 1
 *@src:string 2
 *@n: bytes number
 *Return:string
 */


char *_strncat(char *dest, char *src, int n)
{
	int j;
	int k;
	char *s = dest;

	j = 0;
	k = 0;
	while (dest[j] != '\0')
		j++;
	while (src[k] != '\0' && k < n)
	{
		dest[j] = src[k];
		j++;
		k++;
	}
	if (k < n)
		dest[j] = '\0';
	return (s);
}







/**
 **_strchr - locates char in string
 *Description:locates characters
 *@s:string
 *@c: char
 *Return: a pointer
 */





char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}






/**
 **_strncpy - copys string
 *Description:copy string to n number of char
 *@dest:string
 *@src:source string
 *@n:amount of char to copy
 *Return:string
 */




char *_strncpy(char *dest, char *src, int n)
{
	int j, k;
	char *s = dest;

	j = 0;
	while (src[j] != '\0' && j < n - 1)
	{
		dest[j] = src[j];
		j++;
	}
	if (j < n)
	{
		k = j;
		while (k < n)
		{
			dest[k] = '\0';
			k++;
		}
	}
	return (s);
}












