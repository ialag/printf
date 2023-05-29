#include "main.h"

/**
 * print_from_to - prints a range of char addr
 * @start: start addr
 * @stop: stop addr
 * @except: expt addr
 * Return: nbr bytes printed
*/
int print_from_to(char *start, char *stop, char *except)
{
int sum = 0;
while (start <= stop)
{
if (start != except)
{
sum += _putchar(*start);
}
start++;
}
return (sum);
}

/**
 * print_rev - prints string in reverse
 * @ap: string
 * @params: the parameters struct
 * Return: number of bytes printed
*/
int print_rev(va_list ap, params_t *params)
{
int len, sum = 0;
char *string = va_arg(ap, char *);
(void)params;

if (string)
{
for (len = 0; string[len]; len++)
;
string--;
for (; len > 0; len--, string--)
{
sum += _putchar(*string);
}
}
return (sum);
}

/**
 * print_rot13 - prints string in rot13
 * @ap: string
 * @params: the parameters struct
 * Return: number of bytes printed
*/
int print_rot13_string(char *str);
int print_rot13(va_list ap, params_t *params)
{
char *a = va_arg(ap, char *);
(void)params;
if (a)
{
return (print_rot13_string(a));
}
return (0);
}
/**
 * print_rot13_string - prints string in rot13
 * @str: string to print
 * Return: number of bytes printed
*/
int print_rot13_string(char *str)
{
int count = 0;
char arr[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
while (*str)
{
if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
{
int index = *str - 'A';
if (*str >= 'a' && *str <= 'z')
index = *str - 'a' + 26;
count += _putchar(arr[index]);
}
else
{
count += _putchar(*str); }
str++;
}
return (count);
}
