#include "main.h"

/**
 * print_string - Prints a string to the standard output (stdout).
 * @args: A va_list with the string to print as an argument.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char*); /* Extract the string argument from va_list */

    int num_written; /* Declare the variable here */

    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    num_written = write(1, str, len); /* Print the string to the standard output */

    return (num_written);
}
