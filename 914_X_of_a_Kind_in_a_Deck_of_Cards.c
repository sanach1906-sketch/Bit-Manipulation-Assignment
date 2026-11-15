int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

bool hasGroupsSizeX(int* deck, int deckSize) {
    int freq[10000] = {0};

    for (int i = 0; i < deckSize; i++) {
        freq[deck[i]]++;
    }

    int groupSize = 0;

    for (int i = 0; i < 10000; i++) {
        if (freq[i] > 0) {
            groupSize = gcd(groupSize, freq[i]);
        }
    }

    return groupSize >= 2;
}