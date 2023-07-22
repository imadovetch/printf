
#include "main.h"

int _printf(const char * const format, ...)
{
    int i = 0;
    int j;
    int count = 0;
 

    opera_t type[11] = {
        {"c", _putchar_va_list, _putchar}, 
        {"s", print_string},
        {"i", _itoa},
        {"d", _itoa},
        {"x", print_hex},
        {"X", print_HEX},
        {"u", _puts_unsigned},
        {"r", _puts_reversed},
        {"b", _puts_binary},
        {"S", _putS},
        {"p", _putP},
        {"o", print_octal}
    };

    va_list args;

    va_start(args, format);
    if (!format)
        return (-1);

    while (format[i])
    {
        int x = i, spa;
        
        if (format[x] == '%' && format[x + 1])
        {
            if(format[x] == '%' && format[x + 1] == '%')
            {     
                 _putchar(format[x]);
                    i += 2;
                    continue;
            }
            if(format[x + 1] == ' ' && format[x + 2])
            {   for(spa = (x + 1);spa < 100;spa++){
                    if(format[spa] == ' ')
                    {
                        if(spa == i + 1)
                            _putchar(' ');
                        x++; 
                    }else{i = x ;break;}
                }
            }
            
            for(j = 0; j < 11; j++)
            {
                if(format[x + 1] == type[j].key[0])
                {
                    count += type[j].f(args);
                    i++;  
                    break;
                }
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
    return count;
}
