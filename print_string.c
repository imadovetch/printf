#include "main.h"

/**
 * print_string - Prints a string to the standard output (stdout).
 * @args: A va_list with the string to print as an argument.
 * @flags: The flags indicating special formatting options (unused in this function).
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int print_string(va_list args, int flags)
{
    char *str = va_arg(args, char*);
    int num_written = 0;

    if (str == NULL)
    {
        num_written += write(1, "(null)", 6);
        return num_written;
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        _putchar(str[i]);
        num_written++;
    }

    return num_written;
}
