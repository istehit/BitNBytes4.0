#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

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

    // Merge both arrays, then read the middle off directly
    vector<int> merged;
    merged.insert(merged.end(), a.begin(), a.end());
    merged.insert(merged.end(), b.begin(), b.end());
    sort(merged.begin(), merged.end());

    int total = n + m;

    if (total % 2 == 1) {
        cout << merged[total / 2] << endl;
        return 0;
    }

    double median = (merged[total / 2 - 1] + merged[total / 2]) / 2.0;

    if (median == (int)median)
        cout << (int)median << endl;
    else
        cout << fixed << setprecision(1) << median << endl;

    return 0;
}
/*
Time Complexity: O((N + M) log(N + M))
Space Complexity: O(N + M)
*/
