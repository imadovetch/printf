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
        {"c", _putchar_va_list, NULL},
        {"s", print_string, NULL},
        {"i", _itoa, NULL},
        {"d", _itoa, NULL},
        {"x", print_hex, NULL},
        {"X", print_HEX, NULL},
        {"u", _puts_unsigned, NULL},
        {"r", _puts_reversed, NULL},
        {"b", _puts_binary, NULL},
        {"S", _putS, NULL},
        {"o", print_octal, NULL},
        {"p", _putP, NULL},
        {"R", printf_rot13, NULL}
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
            if (!format[x + 1])
            {
                _putchar('-');
                count--;
            }

            if (!format[x + 1] && format[x + 2])
            {
                count++;
            }

            // Handle the flag characters: +, space, #
            Bool = true;
            char flag_plus = 0, flag_space = 0, flag_hash = 0;
            while (format[x + 1] == '+' || format[x + 1] == ' ' || format[x + 1] == '#')
            {
                if (format[x + 1] == '+')
                    flag_plus = 1;
                else if (format[x + 1] == ' ')
                    flag_space = 1;
                else if (format[x + 1] == '#')
                    flag_hash = 1;
                x++;
            }

            for (j = 0; j < structsize; j++)
            {
                if (format[x] == '%' && format[x + 1] != type[j].key[0] && format[x + 1] != ' ')
                {
                    Bool = true;
                }
                if (format[x + 1] == type[j].key[0])
                {
                    Bool = false;
                    if (flag_plus && (type[j].key[0] == 'd' || type[j].key[0] == 'i'))
                        _putchar('+');
                    else if (flag_space && (type[j].key[0] == 'd' || type[j].key[0] == 'i'))
                        _putchar(' ');

                    count += type[j].f(args);

                    // Handle the flag character: #
                    if (flag_hash && type[j].key[0] == 'o')
                        _putchar('0');
                    else if (flag_hash && (type[j].key[0] == 'x' || type[j].key[0] == 'X'))
                    {
                        _putchar('0');
                        _putchar(type[j].key[0]);
                    }

                    i++;
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



