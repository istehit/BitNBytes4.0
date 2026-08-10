#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100005

char message[MAX_SIZE], pattern[MAX_SIZE];

int main() {
    fgets(message, MAX_SIZE, stdin);
    fgets(pattern, MAX_SIZE, stdin);
    message[strcspn(message, "\n")] = '\0';
    pattern[strcspn(pattern, "\n")] = '\0';

    int messageLen = strlen(message);
    int patternLen = strlen(pattern);
    int neededCount[26] = {0};
    int windowCount[26] = {0};

    for (int i = 0; i < patternLen; i++) {
        neededCount[pattern[i] - 'a']++;
    }

    int requiredChars = 0;
    for (int i = 0; i < 26; i++) {
        if (neededCount[i] > 0) {
            requiredChars++;
        }
    }

    int matchedChars = 0;
    int windowStart = 0;
    int bestLen = messageLen + 1;
    int bestStart = 0;

    for (int windowEnd = 0; windowEnd < messageLen; windowEnd++) {
        int rightChar = message[windowEnd] - 'a';
        windowCount[rightChar]++;

        if (neededCount[rightChar] > 0 && windowCount[rightChar] == neededCount[rightChar]) {
            matchedChars++;
        }

        while (matchedChars == requiredChars) {
            if (windowEnd - windowStart + 1 < bestLen) {
                bestLen = windowEnd - windowStart + 1;
                bestStart = windowStart;
            }

            int leftChar = message[windowStart] - 'a';
            windowCount[leftChar]--;
            if (neededCount[leftChar] > 0 && windowCount[leftChar] < neededCount[leftChar]) {
                matchedChars--;
            }

            windowStart++;
        }
    }

    if (bestLen > messageLen) {
        printf("NONE\n");
    } else {
        for (int i = bestStart; i < bestStart + bestLen; i++) {
            putchar(message[i]);
        }
        printf("\n");
    }

    return 0;
}