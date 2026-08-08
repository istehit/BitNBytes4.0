#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long answer = (1LL << n) - 1;

    cout << answer << endl;

    return 0;
}
/*
Time Complexity: O(1)
Space Complexity: O(1)
*/
