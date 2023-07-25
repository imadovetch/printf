#include "main.h"

/**
 * _itoa - Converts an integer to a string and prints it.
 * @args: A va_list with the integer to convert as an argument.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _itoa(va_list args)
{
     int i = va_arg(args, int);
    int j = 0;
    char buffer[20];
    int index = 0;
    

    if (i == 0)
    {
        _putchar('0');
        return 1;
    }

    if (i < 0)
    {
        _putchar('-');
        j++;
        i = -i;
    }
    else if (is_plus_flag_present)
    {
        _putchar('+');
        j++;
    }
    else if (is_space_flag_present)
    {
        _putchar(' ');
        j++;
    }

    
    index = 0;


    while (i > 0)
    {
        buffer[index++] = (i % 10) + '0';
        i /= 10;
    }


    while (index > 0)
    {
        _putchar(buffer[--index]);
        j++;
    }

    return j;
}
