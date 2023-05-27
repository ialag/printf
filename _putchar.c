#include "main.h"

/**
 * _putchar - A function prints the character c to stdout
 * @c: the character to print
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}




/**
 * _puts - a function that print a string
 * @string: the string to print
 * Return: length of the string
 */

int _puts(char *string)
{
	int l;

	l = 0;
	if (!string)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (string[1])
	{
		write(1, &string[1], 1);
		l++;
	}
	return (1);
}
