#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: The format string to print.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *const format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}

	count = parse_format(format, args);

	va_end(args);
	return (count);
}

/**
 * parse_format - Parse the format string and print accordingly.
 * @format: The format string to print.
 * @args: The va_list of arguments.
 * Return: The number of characters printed (excluding the null byte).
 */
int parse_format(const char *format, va_list args)
{
	int i = 0;
	int count = 0;
	size_t structsize;

	opera_t type[] = {
		{"c", _putchar_va_list, NULL}, {"s", print_string, NULL},
		{"i", _itoa, NULL}, {"d", _itoa, NULL},
		{"x", print_hex, NULL}, {"X", print_HEX, NULL},
		{"u", _puts_unsined, NULL},
		{"r", _puts_reversed, NULL},
		{"b", _puts_binary, NULL},
		{"S", _putS, NULL}, {"o", print_octal, NULL},
		{"p", _putP, NULL}, {"R", printf_rot13, NULL}
	};
	structsize = sizeof(type) / sizeof(type[0]);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != ' ' && !format[i + 1])
			return (count = -1);
		if (format[i] == '%' && format[i + 1])
		{
			if (format[i] == '%' && format[i + 1] == '%')
			{
				count += _putchar(format[i]);
				i += 2;
				continue;
			}
			if (format[i + 1] == ' ' && format[i + 2])
				i = handle_spaces(format, i);
			count += handle_format(format, &i, args, type, structsize);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	return (count);
}

/**
 * handle_format - Handle the format specifier
 * @format: The format string to print.
 * @i: The index of the current format specifier.
 * @args: The va_list of arguments.
 * @type: Array of opera_t structs containing format specifiers and functions.
 * @structsize: The size of the type array.
 * Return: The number of characters printed (excluding the null byte).
 */
int handle_format(const char *format,
int *i, va_list args, opera_t type[], int structsize)
{
	int count = 0;
	bool HOOL, Bool;
	int j;
	int x = *i;

	if (format[x] == '%' && format[x + 1])
	{
		if (format[x + 1] == ' ' && format[x + 2])
			*i = handle_spaces(format, *i);
		Bool = true;
		for (j = 0; j < structsize; j++)
		{
			HOOL = true;
			if (format[x] == '%' && format[x + 1]
			!= type[j].key[0] && format[x + 1] != ' ')
			{
				Bool = true;
				HOOL = false;
			}
			if (format[x + 1] == type[j].key[0])
			{
				Bool = false;
				count += type[j].f(args);
				*i += 1;
				break;
			}
		}
		if (false == HOOL)
			count++;
		if (Bool == true)
			_putchar('%');
	}
	return (count);
}

/**
 * handle_spaces - Handle spaces in the format string.
 * @format: The format string.
 * @i: The index where the spaces are encountered.
 * Return: The updated index after handling spaces.
 */
int handle_spaces(const char *format, int i)
{
	int spa;

	for (spa = (i + 1); spa < 100; spa++)
	{
		if (format[spa] == ' ')
		{
			if (spa == i + 1)
				_putchar(' ');
			i++;
		}
		else
		{
			break;
		}
	}
	return (i);
}
