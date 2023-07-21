#include "main.h"

int _itoa(va_list args) {
    int n = va_arg(args, int);
    int div = 1;
    int count = 0;
    
    va_list tmp_args;
    va_start(tmp_args, args);

    if (n < 0) {
        va_copy(tmp_args, args);
        _putchar(tmp_args);
        n = -n;
        count++;
    }

    int temp = n;
    while (temp > 9) {
        temp /= 10;
        div *= 10;
    }

    while (div >= 1) {
        va_copy(tmp_args, args);
        _putchar(tmp_args);
        n %= div;
        div /= 10;
        count++;
    }

    va_end(tmp_args);
    return count;
}

