#include "main.h"

/**
 * _puts_binary - Prints the binary representation of an unsigned integer.
 * @args: A va_list with the unsigned integer to print as an argument.

>>>>>>> simo
 * Return: The number of characters printed (excluding the null byte).
 */
int _puts_binary(va_list args)
{

	unsigned int num = va_arg(args, unsigned int);
	int num_bits = sizeof(num) * 8;
	unsigned int mask = 1U << (num_bits - 1);
	int chars_printed = 0;
	int i;

	for (i = 0; i < num_bits; i++)
	{
		_putchar((num & mask) ? '1' : '0');
		mask >>= 1;
		chars_printed++;
	}

	return chars_printed;

}

