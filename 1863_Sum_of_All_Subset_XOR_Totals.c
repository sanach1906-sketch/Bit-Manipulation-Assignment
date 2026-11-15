int subsetXORSum(int* nums, int numsSize) {
    int total = 0;
    int subsets = 1 << numsSize;

    for (int i = 0; i < subsets; i++) {
        int xorValue = 0;

        for (int j = 0; j < numsSize; j++) {
            if (i & (1 << j)) {
                xorValue ^= nums[j];
            }
        }

        total += xorValue;
    }

    return total;
}