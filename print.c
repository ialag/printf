#include "main.h"

/**
 * custom_specifiers - a function that cheks on custom specifiers
 * @list: the arguments list
 * @type: specifiers
 * @length: the length of the string
 */

void custom_specifiers(va_list list, char type, int *length)
{
	if (type == '%')
	{
		_putchar('%');
		(*length)++;
	}
	else if (type == 'c')
		(*length) += _putchar(va_arg(list, int));
	else if (type == 's')
		(*length) += _puts(va_arg(list, char*));
	else if (type == 'i' || type == 'd')
		print_number(va_arg(list, int), length);
	/*else if (type == 'o')*/
		/*(*length) = (*length) + print_octal(va_arg(list, int));*/
}
