#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
	/**** Prototypes ****/
int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *string);
void custom_specifiers(va_list list, char type, int *length);

void print_number(long n, int *length);

void *_realloc(void *p, unsigned int old_size, unsigned int new_size);

void _unsigned_int(unsigned long n, int *length);

int print_octal(unsigned int num);

#endif
