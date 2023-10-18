#include"shell.h"



/**
 *_eputs - prints input
 *Description:print input
 *@str:string
 *Return:void
 */




void _eputs(char *str)
{
        int a = 0;

        if (!str)
                return;

        while (str[a] != '\0')
        {
                _eputchar(str[a]);
                a++;
        }
}






/**
 *_eputchar - write char in stderr
 *Description:write char to stderr
 *@c:char
*Return: int
 */



int _eputchar(char c)
{
        static int i;
        static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
                write(2, buf, i);
                i = 0;
        }

        if (c != BUF_FLUSH)
                buf[i++] = c;

        return (1);
}








/**
 *_putsfd -print input str
 *Description:print str
 *@str:string
 *@fd:filedescriptor
 *Return:int
 */



int _putsfd(char *str, int fd)
{
        int i = 0;

        if (!str)
                return (0);

        while (*str)
        {
                i += _putfd(*str++, fd);
        }

        return (i);
}







/**
 *_putfd - write char to fd
 *Description:write charachter to filedescriptor
 *@c:char
 *@fd:filedescriptor
 *Return:int
 */



int _putfd(char c, int fd)
{
        static int i;
        static char buf[WRITE_BUF_SIZE];

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
                write(fd, buf, i);
                i = 0;
        }

        if (c != BUF_FLUSH)
                buf[i++] = c;

        return (1);
}




/**
 *convert_number - itoa clone
 *Description:convert number to string
 *@num:numbers
 *@base:bases
 *@flags:argumment flags
 *Return:char
 */





char *convert_number(long int num, int base, int flags)
{
        static char *array;
        static char buffer[50];
        char sign = 0;
        char *ptr;
        unsigned long n = num;

        if (!(flags & CONVERT_UNSIGNED) && num < 0)
        {
                n = -num;
                sign = '-';

        }

        array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";

        ptr = &buffer[49];

        *ptr = '\0';

        do      {
                *--ptr = array[n % base];
                n /= base;
        } while (n != 0);


        if (sign)
                *--ptr = sign;

        return (ptr);
}
