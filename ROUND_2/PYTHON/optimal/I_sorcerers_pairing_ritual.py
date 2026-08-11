# Optimal Approach - O(N log(max_sum)) time using a frequency map (Counter).
# For every distinct value v, check all powers of two p and see how many
# values (p - v) exist, avoiding the O(N^2) all-pairs comparison.

import sys
from collections import Counter


def solve(arr):
    cnt = Counter(arr)
    max_val = max(arr)
    max_sum = 2 * max_val
    powers = []
    p = 2
    while p <= max_sum:
        powers.append(p)
        p <<= 1
    if not powers:
        powers = [2]

    ans = 0
    for v in cnt:
        c_v = cnt[v]
        for p in powers:
            comp = p - v
            if comp < v:
                continue
            if comp not in cnt:
                continue
            if comp == v:
                ans += c_v * (c_v - 1) // 2
            else:
                ans += c_v * cnt[comp]

    return ans


if __name__ == "__main__":
    data = sys.stdin.read().split()
    n = int(data[0])
    arr = list(map(int, data[1:1 + n]))
    print(solve(arr))
