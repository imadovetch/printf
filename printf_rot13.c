#include "main.h"

/**
 * printf_rot13 - Encodes a string using the rot13-
 * -cipher and prints it to the console.
 * @args: Variadic list containing the string to be encoded.
 * Return: The number of characters printed.
 */
int printf_rot13(va_list args)
{
	int  i, j, counter = 0;
	int k = 0;
	char *s = va_arg(args, char*);
	char a[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char b[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i]; i++)
	{
		k = 0;
		for (j = 0; a[j] && !k; j++)
		{
			if (s[i] == a[j])
			{
				_putchar(b[j]);
				counter++;
				k = 1;
			}
		}
		if (!k)
		{
			_putchar(s[i]);
			counter++;
		}
	}
	return (counter);
}
