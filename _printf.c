#include "main.h"


/**
 * _printf - Custom printf function.
 * @format: The format string to print.
>>>>>>> simo
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char * const format, ...)
{

	int i = 0;
	int j;
	int count = 0;
	int structsize;
	bool Bool;
	bool HOOL;
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
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}

	while (format[i])
	{
		int x = i, spa;
		if(format[i] == '%' && format[i + 1] == ' ' )
			return count = -1;
		if (format[i] == '%' && format[i + 1] != ' '&& !format[i + 1]  )
		{        return count = -1;}


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
				HOOL = true;
				if (format[x] == '%' && format[x + 1] != type[j].key[0] && format[x + 1] != ' ')
				{
					Bool = true;
					HOOL = false;

				}
				if (format[x + 1] == type[j].key[0])
				{
					Bool = false;
					count += type[j].f(args);
					i++;
					break;
				}
			}
			if(HOOL == false)
				count++;
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
