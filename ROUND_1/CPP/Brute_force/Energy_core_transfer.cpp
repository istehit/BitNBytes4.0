#include <iostream>
using namespace std;

long long moves = 0;

void hanoi(int n, char from, char aux, char to) {
    if (n == 0)
        return;

    hanoi(n - 1, from, to, aux);

    moves++;

    hanoi(n - 1, aux, from, to);
}

int main() {
    int n;
    cin >> n;

    hanoi(n, 'A', 'B', 'C');

    cout << moves << endl;

    return 0;
}
/*
Time Complexity: O(2^n)
Space Complexity: O(n) recursion stack
*/
