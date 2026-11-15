#include <stdlib.h>

int* grayCode(int n, int* returnSize) {
    int size = 1;
    int* result = malloc((1 << n) * sizeof(int));

    result[0] = 0;

    for (int i = 0; i < n; i++) {
        int bit = 1 << i;

        for (int j = size - 1; j >= 0; j--) {
            result[size + (size - 1 - j)] = result[j] | bit;
        }

        size *= 2;
    }

    *returnSize = size;
    return result;
}