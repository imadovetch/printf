#include "main.h"

int _puts_reversed(char *str) {
    int length = 0;
    char *start = str;

    // Calculate the length of the string
    while(*start) {
        length++;
        start++;
    }

    // Now, print the string in reverse
    for(int i = length - 1; i >= 0; i--) {
        _putP(str[i]);
    }

    return length;  // Return the length of the string.
}