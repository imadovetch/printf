#include "main.h"

int _puts_unsigned(va_list args) {
    unsigned int n = va_arg(args, unsigned int);
    int count = 0;

    if (n == 0) {
        putchar('0');
        count++;
    } else {
        unsigned int temp = n;
        // Calculate the number of digits in n
        while (temp != 0) {
            count++;
            temp /= 10;
        }

        // Print each digit
        temp = 1;
        for (int i = 1; i < count; i++)
            temp *= 10;
        
        while (temp > 0) {
            int digit = n / temp;
            n %= temp;
            temp /= 10;
            putchar('0' + digit);
        }
    }
    
    return count;
}
