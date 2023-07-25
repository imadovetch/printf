#include "main.h"

/**
 * _itoa - Converts an integer to a string and prints it.
 * @args: A va_list with the integer to convert as an argument.

>>>>>>> simo
 * Return: The number of characters printed (excluding the null byte).
 */
int _itoa(va_list args)
{

	long int i = va_arg(args, int);
	int j = 0;
	char buffer[20]; /* Declare the variable here */
	int index;

	if (i == 0)
	{
		_putchar('0');
		return 1;
	}

	if (i < 0)
	{
		_putchar('-');
		j++;
		i = -i;
	}


	index = 0;


	while (i > 0)
	{
		buffer[index++] = (i % 10) + '0';
		i /= 10;
	}


	while (index > 0)
	{
		_putchar(buffer[--index]);
		j++;
	}

	return j;

}
