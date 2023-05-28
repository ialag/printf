#include "main.h"


/**
 * _printf - function that print the formatted string
 * @format: formatted string
 *
 *
 * Return: nombre bytes printed  of the string
 */
int _printf(const char *format, ...)
{
	int sum = 0;
	char *p, *start;
	va_list ap;
	params_t params = PARAMS_INIT;

	va_start(ap, format);


	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		init_params(&params, ap);
		if (*p != '%')
		{
			sum = sum + _putchar(*p);
				continue;
		}
		start = p;
		p++;
		while (get_flag(p, &params))
		{
			p++;
		}
		p = get_width(p, &params, ap);
		p = get_precision(p, &params, ap);
		if (get_modifier(p, &params))
			p++;
		if (!get_specifier(p))
			sum = sum + print_from_to(start, p,
				params.l_modifier || params.h_modifier ? p - 1 : 0);
		else
			sum = sum + get_print_func(p, ap, &params);
	}
	_putchar(BUF_FLUSH);
	va_end(ap);
	return (sum);
}
