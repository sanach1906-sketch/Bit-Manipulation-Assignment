#include <string.h>

int maxProduct(char** words, int wordsSize) {
    int masks[1000] = {0};
    int maxProduct = 0;

    for (int i = 0; i < wordsSize; i++) {
        for (int j = 0; words[i][j] != '\0'; j++) {
            masks[i] |= 1 << (words[i][j] - 'a');
        }
    }

    for (int i = 0; i < wordsSize; i++) {
        for (int j = i + 1; j < wordsSize; j++) {
            if ((masks[i] & masks[j]) == 0) {
                int product = strlen(words[i]) * strlen(words[j]);

                if (product > maxProduct) {
                    maxProduct = product;
                }
            }
        }
    }

    return maxProduct;
}