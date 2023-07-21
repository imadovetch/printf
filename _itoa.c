#include "main.h"

int _itoa(va_list args) {
    int i = va_arg(args, int);
    int j = 0;

    if (i == 0) {
        _putchar('0');
        return 1;
    }

    if (i < 0) {
        _putchar('-'); // Print the negative sign
        j++; // Increment j to account for the negative sign
        i = -i; // Convert the number to positive for processing
    }

    // Temporary buffer to store the digits in reverse order
    char buffer[20];
    int index = 0;

    // Extract each digit from the number and store them in the buffer
    while (i > 0) {
        buffer[index++] = (i % 10) + '0';
        i /= 10;
    }

    // Print the digits in the correct order
    while (index > 0) {
        _putchar(buffer[--index]);
        j++;
    }

    return j; // Return the total number of characters printed
}
