#include "main.h"

/**
 * _putP - Prints the address of a pointer in hexadecimal format.
 * @args: A va_list with the pointer to print as an argument.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _putP(va_list args)
{
	void *ptr = va_arg(args, void *);
	unsigned long int value = (unsigned long int)ptr;
    int i;
    int result;

	if (value == 0)
	{
		return (_printf("0x0"));
	}
	else
	{
		char *buffer = malloc(21); /* max 20 digits + null terminator */
		int count = 0;
		while (value > 0)
		{
			int digit = value % 16;
			buffer[count++] = (digit < 10) ? digit + '0' : digit - 10 + 'a';
			value /= 16;
		}
		buffer[count] = '\0';
		for (i = 0; i < count / 2; i++) /* reverse the string */
		{
			char temp = buffer[i];
			buffer[i] = buffer[count - 1 - i];
			buffer[count - 1 - i] = temp;
		}
		result = _printf("0x%s", buffer);
		free(buffer);
		return result;
	}
}
