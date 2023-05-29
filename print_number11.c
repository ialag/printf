#include "main.h"

/**
 * _isdigit - checks if character is digit
 * @c: the characters to check
 * Return: 1 if digit, 0 otherwise
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;
	return (i);
}

/**
 * print_number - prints a number with options
 * @string: the base number as a string
 * @params: the parameter struct
 * Return: chars printed
 */

int print_number(char *string, params_t *params)
{
	unsigned int i = _strlen(string);
	int neg = (!params->unsign && *string == '-');

	if (!params->precision && *string == '0' && !string[1])
	string = "";
	if (neg)
	{
		string++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--string = '0';
	if (neg)
		*--string = '-';
	if (!params->minus_flag)
		return (print_number_right_shift(string, params));
	else
		return (print_number_left_shift(string, params));
}

/**
 * print_number_right_shift - prints a nbr with options
 * @string: the base nbr as a str
 * @params: the parameter struct
 * Return: chars printed
 */
int print_number_right_shift(char *string, params_t *params)
{
	unsigned int n = 0, neg1, neg2, i = _strlen(string);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg1 = neg2 = (!params->unsign && *string == '-');
	if (neg1 && i < params->width && pad_char == '0' && !params->minus_flag)
		string++;
	else
		neg1 = 0;
	if ((params->plus_flag && !neg2) ||
			(!params->plus_flag && params->space_flag && !neg2))
		i++;
	if (neg1 && pad_char == '0')
		n += _putchar('-');
	if (params->plus_flag && !neg2 && pad_char == '0' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag &&
		params->space_flag && !neg2
		&& !params->unsign && params->zero_flag)
		n += _putchar(' ');
	while (i++ < params->width)
		n = n + _putchar(pad_char);
	if (neg1 && pad_char == ' ')
		n += _putchar('-');
	if ((*params).plus_flag && !neg2 && pad_char == ' ' && !params->unsign)
		n += _putchar('+');
	else if (!params->plus_flag && params->space_flag && !neg2 &&
			!params->unsign && !params->zero_flag)
		n += _putchar(' ');
	n += _puts(string);
	return (n);
}

/**
 * print_number_left_shift - prints a nbr with options
 * @string: base nbr as a sting
 * @params: the parameters struct
 * Return: chars printed
 */
int print_number_left_shift(char *string, params_t *params)
{
	unsigned int n = 0, neg1, neg2, i = _strlen(string);
	char pad_char = ' ';

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg1 = neg2 = (!params->unsign && *string == '-');

	if (neg1 && i < params->width && pad_char == '0' && !params->minus_flag)
		string++;
	else
		neg1 = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		n += _putchar('+'), i++;
	n += _puts(string);
	while (i++ < params->width)
		n += _putchar(pad_char);
	return (n);
}
