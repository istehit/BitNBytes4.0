#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // Rightmost element smaller than the max seen so far
    int right = -1;
    int maxSeen = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < maxSeen)
            right = i;
        else
            maxSeen = arr[i];
    }

    // Already sorted
    if (right == -1) {
        cout << 0 << endl;
        return 0;
    }

    // Leftmost element bigger than the min seen from the right
    int left = -1;
    int minSeen = arr[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > minSeen)
            left = i;
        else
            minSeen = arr[i];
    }

    cout << right - left + 1 << endl;

    return 0;
}
/*
Time Complexity: O(n)
Space Complexity: O(1) extra
*/
