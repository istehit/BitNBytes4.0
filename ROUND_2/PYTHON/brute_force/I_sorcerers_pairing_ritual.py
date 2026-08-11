# Brute Force Approach - check every pair (i, j) with i < j directly,
# and for each pair test whether the sum is a power of two. O(N^2) time,
# far slower than the O(N log(max_sum)) frequency-map optimal solution.

import sys


def is_power_of_two(x):
    return x > 0 and (x & (x - 1)) == 0


def solve(arr):
    n = len(arr)
    count = 0
    for i in range(n):
        for j in range(i + 1, n):
            if is_power_of_two(arr[i] + arr[j]):
                count += 1
    return count


if __name__ == "__main__":
    data = sys.stdin.read().split()
    n = int(data[0])
    arr = list(map(int, data[1:1 + n]))
    print(solve(arr))
