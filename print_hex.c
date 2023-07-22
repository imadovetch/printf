#include "main.h"

int print_hex(va_list args) {
    unsigned int num = va_arg(args, unsigned int);
    char buffer[20];
    int index = 0;

    if (num == 0) {
        _putchar('0'); // If the number is zero, print '0' and return.
        return 1;
    }

    while (num > 0) {
        int remainder = num % 16;
        buffer[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
        num /= 16;
    }

    int num_written = 0;
    while (index > 0) {
        int written = _putchar(buffer[--index]); // Print characters in the correct order.
        if (written > 0) {
            num_written += written;
        }
    }

    return num_written;
}
