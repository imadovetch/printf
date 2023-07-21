#include "main.h"

int _putchar(char c);  

int _putP(va_list args) {
    
    void *ptr = va_arg(args, void *);

    const char hexDigits[] = "0123456789abcdef";
    char buffer[20]; 
    uintptr_t value = (uintptr_t)ptr;
    int count = 0;

    
    for(int i = sizeof(value)*2-1; i >= 0; i--) {
        buffer[i] = hexDigits[value & 0xF];
        value >>= 4;
        count++;
    }

  
    for(int i = 0; i < count; i++) {
        _putchar(buffer[i]);
    }

    return count;
}