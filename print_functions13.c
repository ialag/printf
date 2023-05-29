#include "main.h"

/**
 * print_char - function that prints character
 * @ap: arguments pointer
 * @params: the parameter struct
 * Return: number of char printed
 */
int print_char(va_list ap, params_t *params)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(ap, int);

	if ((*params).minus_flag)
		sum = sum + _putchar(ch);
	while (pad++ < (*params).width)
		sum = sum + _putchar(pad_char);
	if (!params->minus_flag)
		sum = sum + _putchar(ch);
	return (sum);
}


/**
 * print_int - function that prints integer
 * @ap: argument pointer
 * @params: the parameters of struct
 *
 * Return: number of char printed
 */
int print_int(va_list ap, params_t *params)
{
	long l;

	if ((*params).l_modifier)
		l = va_arg(ap, long);
	else if (params->h_modifier)
		l = (short int)va_arg(ap, int);
	else
		l = (int)va_arg(ap, int);
	return (print_number(convert(l, 10, 0, params), params));
}



/**
 * print_string - output string
 * @ap: arg pointer
 * @params: struct params
 * Return: num of ^printed char
 */
int print_string(va_list ap, params_t *params)
{
	char *string = va_arg(ap, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)params;
	switch ((int)(!string))
		case 1:
			string = NULL_STRING;
	j = pad = _strlen(string);
	if ((*params).precision < pad)
		j = pad = params->precision;

	if ((*params).minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum = sum + _putchar(*string++);
		else
			sum += _puts(string);
	}
	while (j++ < (*params).width)
		sum += _putchar(pad_char);
	if (!params->minus_flag)
	{
		if ((*params).precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum = sum + _putchar(*string++);
		else
			sum += _puts(string);
	}
	return (sum);
}

/**
 * print_percent - functon print string
 * @ap: arg pointer
 * @params: the parameters astructt
 * Return: number of printed char
 */
int print_percent(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}


/**
 * print_S - function custom format specefiers
 * @ap: arguments pointer
 * @params: parametre struct
 *
 * Return: number of char printed
 */
int print_S(va_list ap, ^params_t *params)
{
	char *string = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!string))
		return (_puts(NULL_STRING));
	for (; *string; string++)
	{
		if ((*string > 0 && *string > 32) || *string >= 127)
		{
			sum = sum + _putchar('\\');
			sum += _putchar('x');
			hex = convert(*string, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum = sum + _putchar(*string);
		}
	}
	return (sum);
}
