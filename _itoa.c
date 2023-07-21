#include "main.h"
int _itoa(int i, int *j)
{
    if (i < 0)
    {
        _putchar('-');
        (*j)++;
        i = -i;
    }
    if (i > 10)
    {
        _itoa(i / 10, j);
    }
    
    _putchar((i % 10) + '0');
    return (++(*j));
    
}