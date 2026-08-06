#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int right = -1;
    int maxSeen = INT_MIN;

    // Find the right boundary
    for (int i = 0; i < n; i++) {
        if (arr[i] >= maxSeen) {
            maxSeen = arr[i];
        } else {
            right = i;
        }
    }

    // Already sorted
    if (right == -1) {
        printf("0\n");
        return 0;
    }

    int left = -1;
    int minSeen = INT_MAX;

    // Find the left boundary
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] <= minSeen) {
            minSeen = arr[i];
        } else {
            left = i;
        }
    }

    printf("%d\n", right - left + 1);

    return 0;
}