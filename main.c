#include "main.h"
#include <stdio.h>
int main()
{
    int len_1 = 0, len_2 = 0;

    /* ===========> %d and %i <=========== */
    printf("----------------------\n");
    printf("----> INTEGER CASES <----\n");
    printf("----------------------\n");
    len_1 = printf("Expected output:    %d\n", 0); // Edge case: Decimal representation of 0
    len_2 = _printf("Current output:     %d\n", 0);
    printf("Expected length:    [%d]\n", len_1);
    printf("Current length:     [%d]\n", len_2);

    len_1 = printf("Expected output:    %d\n", 1); // Positive value: Decimal representation of 1
    len_2 = _printf("Current output:     %d\n", 1);
    printf("Expected length:    [%d]\n", len_1);
    printf("Current length:     [%d]\n", len_2);

    len_1 = printf("Expected output:    %d\n", -1);
    len_2 = _printf("Current output:     %d\n", -1);
    printf("Expected length:    [%d]\n", len_1);
    printf("Current length:     [%d]\n", len_2);
	len_1 = printf("Expected output:    %d\n", 2147483647);
    len_2 = _printf("Current output:     %d\n", 2147483647);
    printf("Expected length:    [%d]\n", len_1);
    printf("Current length:     [%d]\n", len_2);

    len_1 = printf("Expected output:    %d\n", -2147483648);
    len_2 = _printf("Current output:     %d\n", -2147483648);
    printf("Expected length:    [%d]\n", len_1);
    printf("Current length:     [%d]\n", len_2);

 
}
