# Optimal Approach - O(log(min(N, M))) binary search on the smaller array
# to find the correct partition point, without merging the arrays.

import sys


def solve(a, b):
    if len(a) > len(b):
        a, b = b, a

    n, m = len(a), len(b)
    lo, hi = 0, n
    half = (n + m + 1) // 2

    while lo <= hi:
        i = (lo + hi) // 2
        j = half - i

        a_left = a[i - 1] if i > 0 else float('-inf')
        a_right = a[i] if i < n else float('inf')
        b_left = b[j - 1] if j > 0 else float('-inf')
        b_right = b[j] if j < m else float('inf')

        if a_left <= b_right and b_left <= a_right:
            if (n + m) % 2 == 1:
                return a_left if a_left > b_left else b_left
            else:
                left_max = a_left if a_left > b_left else b_left
                right_min = a_right if a_right < b_right else b_right
                return (left_max + right_min) / 2
        elif a_left > b_right:
            hi = i - 1
        else:
            lo = i + 1


def format_output(value):
    if isinstance(value, int) or value == int(value):
        return str(int(value))
    return f"{value:.1f}"


if __name__ == "__main__":
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx]); idx += 1
    a = list(map(int, data[idx:idx + n])); idx += n
    m = int(data[idx]); idx += 1
    b = list(map(int, data[idx:idx + m])); idx += m

    result = solve(a, b)
    print(format_output(result))
