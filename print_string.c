#include "main.h"

/**
 * print_string - Prints a string to the standard output (stdout).
 * @args: A va_list with the string to print as an argument.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int print_string(va_list args)
{
    char *str;
    int num_written;
    int len;
    
    str = va_arg(args, char*);
    if(str == NULL)
    {
         int num_written = write(1, "(null)", 6);
        return num_written;
    } 

   
    len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    num_written = write(1, str, len); /* Print the string to the standard output */

    return (num_written);
}
