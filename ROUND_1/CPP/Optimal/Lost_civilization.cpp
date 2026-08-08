#include <iostream>
#include <string>
using namespace std;

int value(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        default:  return 1000;
    }
}

int main() {
    string s;
    cin >> s;

    int ans = 0;
    int n = s.length();

    for (int i = 0; i < n; i++) {

        int curr = value(s[i]);

        if (i + 1 < n && curr < value(s[i + 1])) {
            ans -= curr;
        } else {
            ans += curr;
        }
    }

    cout << ans << endl;

    return 0;
}
/*
Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(1)
*/
