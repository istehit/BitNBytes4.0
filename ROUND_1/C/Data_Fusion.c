#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n, m;

    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    scanf("%d", &m);
    int B[m];
    for (int i = 0; i < m; i++)
        scanf("%d", &B[i]);

    // Always binary search on the smaller array
    if (n > m) {
        int tempN = n;
        n = m;
        m = tempN;

        int temp[m];
        for (int i = 0; i < m; i++)
            temp[i] = B[i];

        for (int i = 0; i < n; i++)
            B[i] = A[i];

        for (int i = 0; i < m; i++)
            A[i] = temp[i];
    }

    int low = 0, high = n;

    while (low <= high) {
        int cutA = (low + high) / 2;
        int cutB = (n + m + 1) / 2 - cutA;

        int leftA = (cutA == 0) ? INT_MIN : A[cutA - 1];
        int rightA = (cutA == n) ? INT_MAX : A[cutA];

        int leftB = (cutB == 0) ? INT_MIN : B[cutB - 1];
        int rightB = (cutB == m) ? INT_MAX : B[cutB];

        if (leftA <= rightB && leftB <= rightA) {

            if ((n + m) % 2 == 0) {
                double median = (max(leftA, leftB) + min(rightA, rightB)) / 2.0;

                if (median == (int)median)
                    printf("%d\n", (int)median);
                else
                    printf("%.1f\n", median);

            } else {
                printf("%d\n", max(leftA, leftB));
            }

            return 0;

        } else if (leftA > rightB) {
            high = cutA - 1;
        } else {
            low = cutA + 1;
        }
    }

    return 0;
}