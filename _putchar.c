#include "main.h"

/**
 * _putchar - A function prints the character c to stdout
 * @c: the character to print
 * Return: On success 1.
 * if error , return -1
 */

int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, 1);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}




/**
 * _puts - a function that print a string
 * @string: the string to print
 * Return: void
 */
int _puts(char *string)
{
	char *a = string;


	while (*string)
		_putchar(*string++);
	return (string - a);
}
