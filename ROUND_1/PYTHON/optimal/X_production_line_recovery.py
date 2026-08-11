# Optimal Approach - O(N) time, O(1) extra space.
# Pass 1 (left -> right): track max seen so far, mark rightmost point
#                          where an element is smaller than that max.
# Pass 2 (right -> left): track min seen so far, mark leftmost point
#                          where an element is larger than that min.

def solve(arr):
    n = len(arr)
    if n <= 1:
        return 0

    left, right = -1, -1

    max_seen = float('-inf')
    for i in range(n):
        if arr[i] < max_seen:
            right = i
        else:
            max_seen = arr[i]

    min_seen = float('inf')
    for i in range(n - 1, -1, -1):
        if arr[i] > min_seen:
            left = i
        else:
            min_seen = arr[i]

    if right == -1:
        return 0
    return right - left + 1


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    print(solve(arr))
