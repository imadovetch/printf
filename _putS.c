#include "main.h"

int _putS(const char* str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    
    int num_written = write(1, str, len);

    return num_written;
}