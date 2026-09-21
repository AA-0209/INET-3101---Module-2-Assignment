/* 
 * INET 3101 - Base conversion implementation
 */

#include <stdio.h>

static void print_digits(unsigned int num, unsigned int base) {
    unsigned int r = num % base;
    
    if (num >= base) {
        print_digits(num / base, base);
    }
    
    const char digits[] = "0123456789abcdef";
    printf("%c", digits[r]);
}

void to_base_n(int num, int base) {
    if (base < 2 || base > 16) {
        fprintf(stderr, "Error: base must be between 2 and 16.\n");
        return;
    }

    unsigned int magnitude;
    if (num < 0) {
        printf("-");
        magnitude = (unsigned int)(-(num + 1)) + 1;
    } else {
        magnitude = (unsigned int)num;
    }

    if (base == 8 && magnitude != 0) {
        printf("0");
    } else if (base == 16) {
        printf("0x");
    }

    print_digits(magnitude, (unsigned int)base);
}

int main(void) {
    printf("Testing Base 8 (21): ");
    to_base_n(21, 8); // Expected: 025
    printf("\n");

    printf("Testing Base 16 (129): ");
    to_base_n(129, 16); // Expected: 0x81
    printf("\n");

    printf("Testing Invalid Base (129, 20):\n");
    fflush(stdout);
    to_base_n(129, 20); // Expected: Error message
    printf("\n");
    
    

    return 0;
}