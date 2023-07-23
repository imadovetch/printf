#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: The format string to print.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char * const format, ...)
{
    int i = 0;
    int j;
    int count = 0;
    int structsize;
    bool Bool;

opera_t type[] = {
    {"c", 0, _putchar_va_list, NULL},
    {"s", 0, print_string, NULL},
    {"i", 0, _itoa, NULL},
    {"d", 0, _itoa, NULL},
    {"x", 0, print_hex, NULL},
    {"X", 0, print_HEX, NULL},
    {"u", 0, _puts_unsigned, NULL},
    {"r", 0, _puts_reversed, NULL},
    {"b", 0, _puts_binary, NULL},
    {"S", 0, _putS, NULL},
    {"o", 0, print_octal, NULL},
    {"p", 0, _putP, NULL},
    {"R", 0, printf_rot13, NULL}
};

    va_list args;

    structsize = sizeof(type) / sizeof(type[0]);

    va_start(args, format);
    if (!format)
    {
        return (-1);
    }

    while (format[i])
    {
        int x = i, spa;
		
        if (format[x] == '%' && format[x + 1])
        {
            
            

            if (format[x] == '%' && format[x + 1] == '%')
            {
                count += _putchar(format[x]);
                i += 2;
                continue;
            }

            if (format[x + 1] == ' ' && format[x + 2])
            {
                for (spa = (x + 1); spa < 100; spa++)
                {
                    if (format[spa] == ' ')
                    {
                        if (spa == i + 1)
                            _putchar(' ');
                        x++;
                    }
                    else
                    {
                        i = x;
                        break;
                    }
                }
            }

            Bool = true;

            for (j = 0; j < structsize; j++)
            {
                if (format[x] == '%' && format[x + 1] != type[j].key[0] && format[x + 1] != ' ')
                {
                    Bool = true;
                }
                if (format[x + 1] == type[j].key[0])
                {
                    Bool = false;
                    count += type[j].f(args);
                    i++;
                    type[j].flags = get_flags(format, &i);
                    break;
                }
            }

            if (Bool == true)
            {
                _putchar('%');
            }
        }
        else
        {
            _putchar(format[x]);
            count++;
        }
        i++;
    }

    va_end(args);
    return (count);
}


