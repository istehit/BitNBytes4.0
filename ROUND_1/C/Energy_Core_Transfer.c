#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long result = (1LL << n) - 1;

    printf("%lld\n", result);

    return 0;
}