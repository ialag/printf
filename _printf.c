#include "main.h"

/**
 * flags - function that checks flags
 * @type: specifier
 * @length: length string
 *
 * Return: 1 if puts smtg, 0 if not
 */
int flags(const char *type, int *length)
{
	if (*type == ' ')
	{
		*length += _putchar(' ');
		return (1);
	}
	else if (*type == '+')
	{
		*length += _putchar('+');
		return (1);
	}
	else if (*type == '#')
	{
		if (*(type + 1) == 'o')
			*length = _putchar('0');
		if (*(type + 1) == 'x' || *(type + 1) == 'X')
			*length = _printf("0x");
		return (1);
	}
	return (0);
}



/**
 * _printf - function that print the formatted string
 * @format: formatted string
 *
 *
 * Return: the length of the string
 */
int _printf(const char *format, ...);
{
	int i;
	int length;
	va_list list;

	i = 0;
	length = 0;
	if (!format || (format[0] == '%' && !format[1]))
		return (1);
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (flags(&format[i], &length))
				i++;
			custom_specifiers(list, format[i], &length);
		}
		else
			length = length + _putchar(format[i]);
		i++;
	}
	va_end(list);
	return (length);
}
