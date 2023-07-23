#include "main.h"

/**
 * get_flags - extracts the flag options from a format specifier
 * @format: the format string to scan
 * @i: a pointer to the current position in the format string
 *
 * Return: the bitwise OR of the flag values
 */
int get_flags(const char *format, int *i)
{
	int j, curr_i;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		for (j = 0; FLAGS_CHAR[j] != '\0'; j++)
			if (format[curr_i] == FLAGS_CHAR[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CHAR[j] == 0)
			break;
	}
	*i = curr_i - 1;

	return (flags);
}