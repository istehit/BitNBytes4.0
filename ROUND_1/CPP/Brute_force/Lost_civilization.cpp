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

        if (i + 1 < n) {

            string pair = s.substr(i, 2);

            if (pair == "IV") {
                ans += 4;
                i++;
            }
            else if (pair == "IX") {
                ans += 9;
                i++;
            }
            else if (pair == "XL") {
                ans += 40;
                i++;
            }
            else if (pair == "XC") {
                ans += 90;
                i++;
            }
            else if (pair == "CD") {
                ans += 400;
                i++;
            }
            else if (pair == "CM") {
                ans += 900;
                i++;
            }
            else {
                ans += value(s[i]);
            }

        } else {
            ans += value(s[i]);
        }
    }

    cout << ans << endl;

    return 0;
}
/*
Time Complexity: O(n) where n is the length of the string.
Space Complexity: O(1)
*/
