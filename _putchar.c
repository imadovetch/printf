#include "main.h"

int _putchar(char c) {
    return write(1, &c, 1);
}

// Additional version of _putchar to handle va_list parameter
int _putchar_va_list(va_list args) {
    char c = va_arg(args, int);
    return write(1, &c, 1);
}
