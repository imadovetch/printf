#include "main.h"

int _printf(const char * const format, ...)
{
    int i = 0;
    int j;
    int count = 0;

    opera_t type[11] = {
        {"c", _putchar_va_list, _putchar}, // Use _putchar_va_list for va_list parameters
        {"s", print_string},
        // Other format specifiers...
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
            count += type[0].f_char(format[i]); // Use _putchar for direct character printing
        }
        i++;
    }

    va_end(args);
    return count;
}
