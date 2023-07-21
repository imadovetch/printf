#include "main.h"

int _puts_binary(va_list args) {
    unsigned int num = va_arg(args, unsigned int);

    // Add this line to define num_bits
    int num_bits = sizeof(num) * 8;

    unsigned int mask = 1U << (num_bits - 1);

    int chars_printed = 0;

    for (int i = 0; i < num_bits; i++) {
        _putchar((num & mask) ? '1' : '0');
        mask >>= 1;
        chars_printed++;
    }

    return chars_printed;
}
