#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    // Negative Vault IDs are never valid
    if (n < 0) {
        printf("NO\n");
        return 0;
    }

    long long original = n;
    long long reversed = 0;
    long long temp = n;

    while (temp > 0) {
        long long digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }

    if (reversed == original) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}