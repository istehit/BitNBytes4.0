# Brute Force Approach - try every possible subarray (l, r), sort a copy of
# it, and check whether the whole array becomes sorted. Return the length
# of the shortest such subarray. Runs in O(N^3 log N) in the worst case
# (O(N^2) subarrays, each needing an O(N log N) sort + O(N) check),
# extremely slow for large N compared to the O(N) optimal solution.

def is_sorted(a):
    return all(a[i] <= a[i + 1] for i in range(len(a) - 1))


def solve(arr):
    n = len(arr)
    if is_sorted(arr):
        return 0

    best = n  # worst case: sort the whole array
    for l in range(n):
        for r in range(l, n):
            candidate = arr[:l] + sorted(arr[l:r + 1]) + arr[r + 1:]
            if is_sorted(candidate):
                length = r - l + 1
                if length < best:
                    best = length
                break  # no need to extend r further once valid for this l

    return best


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    print(solve(arr))
