#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int a[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    qsort(a, n, sizeof(int), compare);

    int found = 0;

    for (int i = 0; i < n - 2; i++) {

        if (i > 0 && a[i] == a[i - 1])
            continue;

        int l = i + 1;
        int r = n - 1;

        while (l < r) {
            int sum = a[i] + a[l] + a[r];

            if (sum == 0) {
                printf("%d %d %d\n", a[i], a[l], a[r]);
                found = 1;

                while (l < r && a[l] == a[l + 1]) l++;
                while (l < r && a[r] == a[r - 1]) r--;

                l++;
                r--;
            }
            else if (sum < 0) {
                l++;
            }
            else {
                r--;
            }
        }
    }

    if (!found)
        printf("NONE");

    return 0;
}