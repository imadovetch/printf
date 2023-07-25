#include "main.h"

/**
 * _putchar - Writes a character to the standard output (stdout).
 * @c: The character to be written.
 * Return: On success, the number of characters written is returned.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _putchar_va_list - Writes a character from a va_list parameter.
 * @args: A va_list containing the character to be written as an argument.
 * Return: On success, the number of characters written is returned.
 *         On error, -1 is returned, and errno is set appropriately.
 */
int _putchar_va_list(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}
