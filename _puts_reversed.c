#include "main.h"

int _puts_reversed(va_list args) {
    char *str = va_arg(args, char*);
    int length = 0;
    char *start = str;

    // Calculate the length of the string
    while(*start) {
        length++;
        start++;
    }

    // Now, print the string in reverse
    for(int i = length - 1; i >= 0; i--) {
        _putchar(str[i]);
    }

    return length;  // Return the length of the string.
}