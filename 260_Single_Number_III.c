#include <stdlib.h>

int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int xorResult = 0;

    for (int i = 0; i < numsSize; i++) {
        xorResult ^= nums[i];
    }

    int rightmostBit = xorResult & (-xorResult);

    int num1 = 0;
    int num2 = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] & rightmostBit) {
            num1 ^= nums[i];
        } else {
            num2 ^= nums[i];
        }
    }

    int* result = malloc(2 * sizeof(int));
    result[0] = num1;
    result[1] = num2;

    *returnSize = 2;
    return result;
}