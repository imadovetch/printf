#include "main.h"

/**
 * _putS - Prints a string (char array) to the standard output (stdout).
 * @args: A va_list with the string to print as an argument.
 *
 * Return: The number of characters written (excluding the null byte).
 */
int _putS(va_list args)
{
	char *str = va_arg(args, char*); /* Retrieve the string from va_list */
    int num_written;
	int len = 0;
    
	while (str[len] != '\0')
	{
		len++;
	}

	num_written = write(1, str, len);

	return num_written;
}
