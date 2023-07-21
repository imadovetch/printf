#include "main.h"

int print_hex(int num) {
    char buffer[20];
    int index = 0;
    do {
        int remainder = num % 16;
        buffer[index++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
        num /= 16;
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