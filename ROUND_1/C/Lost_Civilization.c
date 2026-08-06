#include <stdio.h>
#include <string.h>

int getValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    char s[20];
    scanf("%s", s);

    int n = strlen(s);
    long long total = 0;

    for (int i = 0; i < n; i++) {
        int current = getValue(s[i]);
        int next = (i + 1 < n) ? getValue(s[i + 1]) : 0;

        if (current < next) {
            total -= current;
        } else {
            total += current;
        }
    }

    printf("%lld\n", total);

    return 0;
}