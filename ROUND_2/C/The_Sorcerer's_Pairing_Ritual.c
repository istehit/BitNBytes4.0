#include <stdio.h>

int isPowerOfTwo(long long x) {
    if (x < 2)
        return 0;
    return (x & (x - 1)) == 0;
}

int main() {
    int n;
    scanf("%d", &n);

    long long a[n];

    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }

    long long count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isPowerOfTwo(a[i] + a[j])) {
                count++;
            }
        }
    }

    printf("%lld\n", count);

    return 0;
}