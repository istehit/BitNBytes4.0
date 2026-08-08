#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

// Values are within +/- 10^6, so these act as -infinity and +infinity
const int NEG_INF = -2000000000;
const int POS_INF = 2000000000;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // Always binary search on the smaller array
    if (n > m) {
        swap(a, b);
        swap(n, m);
    }

    int low = 0, high = n;

    while (low <= high) {
        int cutA = (low + high) / 2;
        int cutB = (n + m + 1) / 2 - cutA;

        int leftA = (cutA == 0) ? NEG_INF : a[cutA - 1];
        int rightA = (cutA == n) ? POS_INF : a[cutA];

        int leftB = (cutB == 0) ? NEG_INF : b[cutB - 1];
        int rightB = (cutB == m) ? POS_INF : b[cutB];

        if (leftA <= rightB && leftB <= rightA) {

            // Odd total: median is the largest element on the left
            if ((n + m) % 2 == 1) {
                cout << max(leftA, leftB) << endl;
                return 0;
            }

            double median = (max(leftA, leftB) + min(rightA, rightB)) / 2.0;

            if (median == (int)median)
                cout << (int)median << endl;
            else
                cout << fixed << setprecision(1) << median << endl;

            return 0;
        }

        if (leftA > rightB)
            high = cutA - 1;
        else
            low = cutA + 1;
    }

    return 0;
}
/*
Time Complexity: O(log(min(N, M)))
Space Complexity: O(1)
*/
