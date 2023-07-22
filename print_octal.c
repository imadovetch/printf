#include "main.h"

int print_octal(va_list args) {
    int num = va_arg(args, int);
    char buffer[20];
    int index = 0;

    // Handle the case when the input number is 0 separately
    if (num == 0) {
        _putchar('0');
        return 1;
    }

    // Convert the number to its octal representation in reverse order
    while (num > 0) {
        int remainder = num % 8;
        buffer[index++] = remainder + '0';
        num /= 8;
    }

    int num_written = 0;

    // Print the octal number by reversing the buffer
    while (index > 0) {
        _putchar(buffer[--index]);
        num_written++;
    }

    return num_written;
}
