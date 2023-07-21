#ifndef _HEADER_
#define _HEADER_


#include <stdarg.h>
#include <unistd.h> 
#include <inttypes.h>
#include <limits.h>

typedef struct opera {
	char key;
	int (*f)(va_list);
} opera_t;

int _putchar(va_list args);
int print_string(va_list args);
int _itoa(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int _puts_unsigned(va_list args);
int _puts_reversed(va_list args);
int _puts_binary(va_list args);
int putS(va_list args);
int _putP(va_list args);

#endif
