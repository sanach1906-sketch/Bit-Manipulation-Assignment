
int countSetBits(int n) {
    int count = 0;

    while (n > 0) {
        count += n & 1;
        n = n >> 1;
    }

    return count;
}

int isPrime(int n) {
    if (n < 2)
        return 0;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return 0;
    }

    return 1;
}

int countPrimeSetBits(int left, int right) {
    int result = 0;

    for (int i = left; i <= right; i++) {
        int bits = countSetBits(i);

        if (isPrime(bits)) {
            result++;
        }
    }

    return result;
}
