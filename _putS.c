#include "main.h"

/**
 * _putS - Prints a string (char array) to the standard output (stdout).
 * @args: A va_list with the string to print as an argument.
 * Return: The number of characters written (excluding the null byte).
 */
int _putS(va_list args)
{

	char *str = va_arg(args, char*); /* Retrieve the string from va_list */
	int num_written = 0;
	int len = 0;

	while (str[len] != '\0')
	{
		if (str[len] == '\n')
		{
			_putchar('\\');
			_putchar('x');
			_putchar('0');
			_putchar('A');
			num_written += 4;
		}
		else
		{
			_putchar(str[len]);
			num_written++;
		}
		len++;
	}

	return (num_written);
}

