
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

	  opera_t type[11] = {
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
        {"p", _putP, NULL},
    };

	va_list args;

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
				_putchar(format[x]);
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

			for (j = 0; j < 11; j++)
			{
				if (format[x + 1] == type[j].key[0])
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
	return (count);
}
