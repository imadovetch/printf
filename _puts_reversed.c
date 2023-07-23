#include "main.h"

/**
 * _puts_reversed - Prints a string in reverse order.
 * @args: A va_list with the string to print as an argument.
 * @flags: The flags indicating special formatting options (unused in this function).
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _puts_reversed(va_list args, int flags)
{
    char *str = va_arg(args, char*);
    int length = 0;
    char *start = str;
    int i;

    /* Calculate the length of the string */
    while (*start)
    {
        length++;
        start++;
    }

    /* Now, print the string in reverse */
    for (i = length - 1; i >= 0; i--)
    {
        _putchar(str[i]);
    }

    return length; /* Return the length of the string. */
}

