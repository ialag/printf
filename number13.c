#include "main.h"

/**
 * convert - function that converete
 * @num: a number
 * @base: base
 * @flags: the arguments flags
 * @params:struct paraemetrs
 * Return: string
 */
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ?  "0123456789abcdef" : "123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do {
		*--p = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}

/**
 * print_unsigned - function that rpint unsigned int numbers
 * @ap: pointer argument
 * @params: the parametres of struct
 * Return: bytes gonna be print
 */
int print_unsigned(va_list ap, params_t *params)
{
	unsigned long k;

	if (params->l_modifier)
		k = (unsigned long)va_arg(ap, unsigned long);

	else if (params->h_modifier)
		k = (unsigned short int)va_arg(ap, unsigned int);
	else
		k = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (print_number(convert(k, 10, CONVERT_UNSIGNED, params), params));
}




/**
 * print_adress - function that print adress
 * @ap: arguments pointer
 * @params: the parameters struct
 * Return: bytes printed
 */
int print_adress(va_list ap, params_t *params)
{
	unsigned long int n = va_arg(ap, unsigned long int);
	char *string;

	if (!n)
		return (_puts("(nil)"));

	string = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--string = 'x';
	*--string = '0';
	return (print_number(string, params));
}
