#include "main.h"

int _putS(va_list args) {
    char *str = va_arg(args, char*); // Retrieve the string from va_list

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int num_written = write(1, str, len);

    return num_written;
}
