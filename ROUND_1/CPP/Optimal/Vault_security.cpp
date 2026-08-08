#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Negative Vault IDs are never valid
    if (n < 0) {
        cout << "NO" << endl;
        return 0;
    }

    long long original = n;
    long long reversed = 0;

    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }

    if (reversed == original)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
/*
Time Complexity: O(log10 N)
Space Complexity: O(1)
*/
