#include <stdlib.h>

int maxDotProduct(int* nums1, int nums1Size,
                  int* nums2, int nums2Size) {
    int dp[501][501];

    for (int i = 0; i <= nums1Size; i++) {
        dp[i][0] = -1000000000;
    }

    for (int j = 0; j <= nums2Size; j++) {
        dp[0][j] = -1000000000;
    }

    for (int i = 1; i <= nums1Size; i++) {
        for (int j = 1; j <= nums2Size; j++) {
            int product = nums1[i - 1] * nums2[j - 1];

            int extend = dp[i - 1][j - 1] + product;

            dp[i][j] = product;

            if (extend > dp[i][j])
                dp[i][j] = extend;

            if (dp[i - 1][j] > dp[i][j])
                dp[i][j] = dp[i - 1][j];

            if (dp[i][j - 1] > dp[i][j])
                dp[i][j] = dp[i][j - 1];
        }
    }

    return dp[nums1Size][nums2Size];
}