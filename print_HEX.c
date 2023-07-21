#include "main.h"

int _putchar(char c);  // Make sure you have implemented this function

int print_HEX(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    char buffer[20];
    int index = 0;
    
    do {
        int remainder = num % 16;
        buffer[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        num /= 16;
    } while (num > 0);
    
    int num_written = 0;
    while (index > 0) {
        num_written += _putchar(buffer[--index]);
    }
    
    return num_written;
}