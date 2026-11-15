
#include <stdlib.h>

char* toHex(int num) {
    char* hex = "0123456789abcdef";
    char* result = malloc(9);

    if (num == 0) {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    unsigned int n = (unsigned int)num;
    int i = 0;

    while (n != 0) {
        result[i++] = hex[n & 15];
        n = n >> 4;
    }

    result[i] = '\0';

    for (int j = 0; j < i / 2; j++) {
        char temp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = temp;
    }

    return result;
}
