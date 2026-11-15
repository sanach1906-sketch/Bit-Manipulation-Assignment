int countTriplets(int* nums, int numsSize) {
    int freq[1 << 16] = {0};
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < numsSize; j++) {
            int value = nums[i] & nums[j];
            freq[value]++;
        }
    }

    for (int i = 0; i < numsSize; i++) {
        for (int mask = 0; mask < (1 << 16); mask++) {
            if ((mask & nums[i]) == 0) {
                count += freq[mask];
            }
        }
    }

    return count;
}