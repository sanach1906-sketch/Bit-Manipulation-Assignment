
int binaryGap(int n) {
    int prev = -1;
    int position = 0;
    int maxGap = 0;

    while (n > 0) {
        if (n & 1) {
            if (prev != -1) {
                int gap = position - prev;

                if (gap > maxGap) {
                    maxGap = gap;
                }
            }
            prev = position;
        }

        n = n >> 1;
        position++;
    }

    return maxGap;
}
  