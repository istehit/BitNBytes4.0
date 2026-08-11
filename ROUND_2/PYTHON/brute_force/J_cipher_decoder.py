# Brute Force Approach - check every possible substring of S (all start
# and end positions) and verify whether it contains all required
# character frequencies from P. Runs in O(N^2 * |alphabet|) time
# (or worse), much slower than the O(N) sliding window optimal solution.

import sys
from collections import Counter


def contains_all(window_count, need_count):
    for ch, freq in need_count.items():
        if window_count[ch] < freq:
            return False
    return True


def solve(s: str, p: str):
    n = len(s)
    if len(p) > n:
        return None

    need = Counter(p)
    best = None

    for start in range(n):
        window_count = Counter()
        for end in range(start, n):
            window_count[s[end]] += 1
            if contains_all(window_count, need):
                length = end - start + 1
                if best is None or length < len(best):
                    best = s[start:end + 1]
                break  # smallest valid window for this start found

    return best


if __name__ == "__main__":
    data = sys.stdin.read().split('\n')
    s = data[0].strip()
    p = data[1].strip()

    result = solve(s, p)
    print("NONE" if result is None else result)
