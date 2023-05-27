#include "main.h"

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
			custom_specifiers(list, format[i],&length);
		}
		else
			length = length + _putchar(format[i]);
		i++;
	}
	va_end(list);
	return (length);
}
