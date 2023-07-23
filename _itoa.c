#include "main.h"

/**
 * _itoa - Converts an integer to a string.
 * @args: A va_list with the integer to convert as an argument.
 * @flags: The flags indicating special formatting options.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _itoa(va_list args, int flags)
{
    int num = va_arg(args, int);
    int num_written = 0;

    /* Handle the sign separately */
    if (num < 0)
    {
        _putchar('-');
        num = -num;
        num_written++;
    }
    else if (CHECK_FLAG(flags, PLUS)) /* If the PLUS flag is set, print a plus sign for positive numbers */
    {
        _putchar('+');
        num_written++;
    }

    /* Convert the integer to a string */
    char buffer[12]; /* Assuming 32-bit int, max digits = 11 + 1 (for null terminator) */
    int index = 0;

    if (num == 0)
    {
        buffer[index++] = '0';
    }
    else
    {
        while (num > 0)
        {
            buffer[index++] = num % 10 + '0';
            num /= 10;
        }
    }

    /* Print the string in reverse order */
    while (index > 0)
    {
        _putchar(buffer[--index]);
        num_written++;
    }

    return num_written;
}
