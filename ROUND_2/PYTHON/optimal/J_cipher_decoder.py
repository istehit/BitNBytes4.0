# Optimal Approach - O(N) sliding window using two pointers and a
# frequency counter for the pattern.

import sys
from collections import Counter


def solve(s: str, p: str):
    if len(p) > len(s):
        return None

    need = Counter(p)
    missing = len(p)
    left = 0
    best_len, best_l, best_r = float('inf'), 0, 0

    for right in range(1, len(s) + 1):
        ch = s[right - 1]
        if need[ch] > 0:
            missing -= 1
        need[ch] -= 1

        while missing == 0:
            if right - left < best_len:
                best_len, best_l, best_r = right - left, left, right
            lch = s[left]
            need[lch] += 1
            if need[lch] > 0:
                missing += 1
            left += 1

    if best_len == float('inf'):
        return None
    return s[best_l:best_r]


if __name__ == "__main__":
    data = sys.stdin.read().split('\n')
    s = data[0].strip()
    p = data[1].strip()

    result = solve(s, p)
    print("NONE" if result is None else result)
