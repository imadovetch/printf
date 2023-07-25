#include "main.h"

/**
 * print_hex - Prints an unsigned integer in hexadecimal format.
 * @args: A va_list with the unsigned integer to print as an argument.
 * Return: The number of characters printed (excluding the null byte).
 */
int print_hex(va_list args)
{

	unsigned int num = va_arg(args, unsigned int);
	int num_written = 0; /* Declare the variable here */
	char buffer[20];
	int index = 0;

	/* Handle the case when the number is 0 separately */
	if (num == 0)
	{
		_putchar('0');
		return 1;
	}

	while (num > 0)
	{
		int remainder = num % 16;
		buffer[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
		num /= 16;
	}

	/* Print the characters in the correct order */
	while (index > 0)
	{
		int written = _putchar(buffer[--index]);
		if (written > 0)
		{
			num_written += written;
		}
	}

	return num_written;

}
