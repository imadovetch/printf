
#include "main.h"

int _printf(const char * const format, ...)
{
    int i = 0;
    int j;
    int count = 0;
    opera_t type[11] = {
        {"c", _putchar},
        {"s", print_string},
        {"i", _itoa},
        {"d", _itoa},
        {"x", print_hex},
        {"X", print_HEX},
        {"u", _puts_unsigned},
        {"r", _puts_reversed},
        {"b", _puts_binary},
        {"S", putS},
        {"p", _putP}
    };

    va_list args;

    va_start(args, format);
    if (!format)
        return (-1);

    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            for(j = 0; j < 11; j++)
            {
                if(format[i + 1] == type[j].key[0])
                {
                    count += type[j].f(args);
                    i++;  // Skip the format specifier
                    break;
                }
            }	
        }
        else
        {
            _putchar(format[i]);
            count++;
        }
        i++;
    }

    va_end(args);
    return count;
}
