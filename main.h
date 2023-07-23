#ifndef _HEADER_
#define _HEADER_

#include <stdarg.h>
#include <unistd.h>
#include <inttypes.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct opera {
    char *key;
    int (*f)(va_list);
    int (*f_char)(char);
} opera_t;

int _printf(const char * const format, ...);

int _putchar_va_list(va_list args);
int _putchar(char c);
int print_string(va_list args);
int _itoa(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int _puts_unsigned(va_list args);
int _puts_reversed(va_list args);
int _puts_binary(va_list args);
int _putS(va_list args);
int _putP(va_list args);
int print_octal(va_list args);
int printf_rot13(va_list args);
#endif