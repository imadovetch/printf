#include "main.h"

/**
 * _puts_unsined - Prints an unsigned integer.
 * @args: A va_list with the unsigned integer to print as an argument
 * Return: The number of characters printed (excluding the null byte).
 */
int _puts_unsined(va_list args)
{
	unsigned int n = va_arg(args, int);
	int count = 0;
	int i;

	if (n == 0)
	{
		_putchar('0');
		count++;
	}
	else
	{
		unsigned int temp = n;

		while (temp != 0)
		{
			count++;
			temp /= 10;
		}

		temp = 1;
		for (i = 1; i < count; i++)
			temp *= 10;

		while (temp > 0)
		{
			int digit = n / temp;

			n %= temp;
			temp /= 10;
			_putchar('0' + digit);
		}
	}
	return (count);
}

