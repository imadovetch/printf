#include "main.h"

int print_octal(int num) {
    char buffer[20];
    int index = 0;
    do {
        int remainder = num % 8;
        buffer[index++] = remainder + '0';
        num /= 8;
    } while (num > 0);

    int num_written = 0;
    while (index > 0) {
        int written = write(1, &buffer[--index], 1);
        if (written > 0) {
            num_written += written;
        }
    }

    return num_written;
}