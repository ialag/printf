#ifndef _PRINTF_H
#define _PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define NULL_STRING "(null)"

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/**
 * struct parameters - the parameters of struct
 *
 * @unsign: unsigned value of the flags
 * @plus_flag: plus_flag specified
 * @space_falg: hashtag_flag specified
 * @hashtag_falg: if_flag specified
 * @zero_flag: if_flag specified
 * @minus_flag: if_flag specified
 * @precision: precision specified
 * @width: field with specified
 *
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modofoer: l_modifier is specified
 */
typedef srtuct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_flag : 1;
	unsigned int space_flag : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag : 1;
	unsigned int minus_flag : 1;
	unsigned int width;
	unsigned int precision;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
}params_t;



/**
 * struct specifier - a structer named specifier
 * @specifier: format
 * @f: its the function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f) (va_list, params_t *);
}specifier_t;



	/* _put.c _putchar.c */
int _puts(char *string);
int _putchar(int c);

	/* printf_functions11.c */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

	/* number11.c */
char *convert(long int num, int base, int flag, params_t *params);
int prnt_unsigned(va_list ap, params_t *params);
int print_adress(va_list ap, params_t *params);


	/* specifier11.c */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

	/* convert_number11.c */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

	/* simple printers11.c */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

	/* params11.c */
void init_params(params_t *params, va_list ap);

	/* string field11.c */
char *get_precision(char *p, params_t *params, va_list ap);

	/* _print11.c */
int _printf(const char *format, ...);

	/* print number11.c */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *string, params_t *params);
int print_number_right_shift(char *string, params_t *params);
int print_number_left_shift(char *string, params_t *params);


#endif
