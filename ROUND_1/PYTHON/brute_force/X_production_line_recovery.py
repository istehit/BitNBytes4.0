def is_sorted(a):
    return all(a[i] <= a[i + 1] for i in range(len(a) - 1))


def solve(arr):
    n = len(arr)
    if is_sorted(arr):
        return 0

    best = n 
    for l in range(n):
        for r in range(l, n):
            candidate = arr[:l] + sorted(arr[l:r + 1]) + arr[r + 1:]
            if is_sorted(candidate):
                length = r - l + 1
                if length < best:
                    best = length
                break  

    return best


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    print(solve(arr))
