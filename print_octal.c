#include "main.h"

/**
 * print_octal - Prints an integer in its octal representation.
 * @args: A va_list with the integer to print as an argument.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int print_octal(va_list args)
{
    int num = va_arg(args, int);
    int num_written = 0; /* Declare the variable here */
    char buffer[20];
    int index = 0;


    if (num == 0)
    {
        _putchar('0');
        return 1;
    }


    while (num > 0)
    {
        int remainder = num % 8;
        buffer[index++] = remainder + '0';
        num /= 8;
    }

    /* Print the octal number by reversing the buffer */
    while (index > 0)
    {
        _putchar(buffer[--index]);
        num_written++;
    }

    return (num_written);
}
