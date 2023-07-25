#include "main.h"

/**
 * print_string - Prints a string to the standard output (stdout).
 * @args: A va_list with the string to print as an argument.
 * Return: The number of characters printed (excluding the null byte).
 */
int print_string(va_list args)
{
	char *str;
	int num_written = 0;
	int i;

	str = va_arg(args, char*);
	if (!str)
	{
		num_written += write(1, "(null)", 6);
		return (num_written);
	}

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
		num_written++;
	}

	return (num_written);
}
