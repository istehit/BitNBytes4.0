#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);

    long long num = n;
    int sign = 1;

    if (num < 0) {
        sign = -1;
        num = -num;
    }

    long long rev = 0;

    while (num > 0) {
        rev = rev * 10 + (num % 10);
        num /= 10;
    }

    rev *= sign;

    if (rev < -2147483648LL || rev > 2147483647LL)
        printf("0");
    else
        printf("%lld", rev);

    return 0;
}