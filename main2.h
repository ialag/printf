#ifndef _PRINTF_H
#define _PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

	/** flags **/
#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASHTAG 8
#define FLAG_SPACE 16

	/** sizes **/
#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
 * struct frmt - function struct
 *
 * @frmt: format
 * @f: the function associated
 */
struct frmt
{
	char frmt;
	int(*f)(va_list,char[],int,int,int,int);
};

/**
 * typedef struct frmt frmt_t - function struct 
 *
 * @frmt: format
 * @frmt_t: the function associated
 */
typdef struct frmt frmt_t;
{
	int _printf(const char *format, ...);
	int handle _print(const char *frmt,int *i,va_list,char buffer[],
			int flags,int width,int precision,int size);
};


		/****** functions ****/
/* functions to print char, string, percent */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width,int precision, int size);

/* functions to print numbers */
int print_int (va_list types 
