#include"shell.h"




/**
 *_strcat - concatentes strings
 *Description:concatinates two strings
 *@dest:destination buf
 *@src:source buf
 *Return: pointer
 */


char *_strcat(char *dest, char *src)
{
	char *p = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (p);
}




/**
 *_strcpy - copy string
 *Description:copy string
 *@dest:destination
 *@src:source
 *Return: pointer
 */


char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}


/**
 *_strdup - to duplicate strings
 *Description:duplicates strings
 *@str:string
 *Return:pointer
 */


char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (ret);
}





/**
 *_strcmp - compare two stings
 *Description:compare two strings
 *@s1:string to compare
 *@s2:second string
 *Return:integer
 */



int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}






/**
 *_strlen - returns string length
 *Description:returns string length
 *@s:string
 *Return:integer
 */


int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}



