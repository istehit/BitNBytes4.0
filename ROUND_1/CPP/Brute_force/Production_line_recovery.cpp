#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());

    // Compare against the fully sorted array to find the first
    // and last position that differ
    int left = 0;
    while (left < n && arr[left] == sorted[left])
        left++;

    // Already sorted
    if (left == n) {
        cout << 0 << endl;
        return 0;
    }

    int right = n - 1;
    while (arr[right] == sorted[right])
        right--;

    cout << right - left + 1 << endl;

    return 0;
}
/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/
