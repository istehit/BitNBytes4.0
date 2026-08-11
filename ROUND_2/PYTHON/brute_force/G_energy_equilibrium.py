# Brute Force Approach - check every possible triplet of indices (i, j, k)
# with a triple nested loop. Runs in O(N^3) time, using a set to remove
# duplicate triplets. Very slow for large N compared to the O(N^2)
# sorted two-pointer optimal solution.

def solve(arr):
    n = len(arr)
    seen = set()

    for i in range(n):
        for j in range(i + 1, n):
            for k in range(j + 1, n):
                if arr[i] + arr[j] + arr[k] == 0:
                    triplet = tuple(sorted((arr[i], arr[j], arr[k])))
                    seen.add(triplet)

    return sorted(seen)


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))

    triplets = solve(arr)
    if not triplets:
        print("NONE")
    else:
        for t in triplets:
            print(*t)
