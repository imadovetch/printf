#include "main.h"
/**
 * _putchar - prints a char to stdout
 * @c: the char to print
 * Return : 1 if it worked 0 if none
*/
int _putchar(char c)
{
    return (write(1, &c, 1));
}