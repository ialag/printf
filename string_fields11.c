#include "main.h"

/**
 * get_precision - gets the precision from the format string
 * @p: the format string
 * @params: the parameters struct
 * @ap: the arg pointer
 * Return: new pointer
 */

char *get_precision(char *p, params_t *params, va_list ap)
{
	int b = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		b = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			b = b * 10 + (*p++ - '0');
	}
	params->precision = b;
	return (p);
}
