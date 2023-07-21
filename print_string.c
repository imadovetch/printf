#include "main.h"

int print_string(va_list args) {
    char *str = va_arg(args, char*); // Extract the string argument from va_list

    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    int num_written = write(1, str, len); // Print the string to the standard output

    return num_written;
}
