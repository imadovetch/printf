#ifndef _HEADER_
#define _HEADER_

#include <stdarg.h>
#include <unistd.h>
#include <inttypes.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

/* PRINTF FLAGS */
#define MINUS 1
#define PLUS 2
#define ZERO 4
#define HASH 8
#define SPACE 16
#define CHECK_FLAG(flags, f) ((flags) & (f))

typedef struct opera {
    char *key;
    int flags;
    int (*f)(va_list, int);
} opera_t;

int _printf(const char * const format, ...);

int _putchar_va_list(va_list args, int flags);
int _putchar(char c);
int print_string(va_list args, int flags);
int _itoa(va_list args, int flags);
int print_hex(va_list args, int flags);
int print_HEX(va_list args, int flags);
int _puts_unsigned(va_list args, int flags);
int _puts_reversed(va_list args, int flags);
int _puts_binary(va_list args, int flags);
int _putS(va_list args, int flags);
int _putP(va_list args, int flags);
int print_octal(va_list args, int flags);
int printf_rot13(va_list args, int flags);
int get_flags(const char *format, int *i);

#endif
