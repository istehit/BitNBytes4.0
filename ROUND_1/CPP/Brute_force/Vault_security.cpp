#include <iostream>
#include <string>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Negative Vault IDs are never valid
    if (n < 0) {
        cout << "NO" << endl;
        return 0;
    }

    string s = to_string(n);

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {

        if (s[left] != s[right]) {
            cout << "NO" << endl;
            return 0;
        }

        left++;
        right--;
    }

    cout << "YES" << endl;

    return 0;
}
/*
Time Complexity: O(d) where d is the number of digits.
Space Complexity: O(d)
*/
