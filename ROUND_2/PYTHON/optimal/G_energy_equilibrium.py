def solve(arr):
    arr.sort()
    n = len(arr)
    result = []

    for i in range(n):
        if i > 0 and arr[i] == arr[i - 1]:
            continue

        l, r = i + 1, n - 1
        while l < r:
            s = arr[i] + arr[l] + arr[r]
            if s == 0:
                result.append((arr[i], arr[l], arr[r]))
                l += 1
                r -= 1
                while l < r and arr[l] == arr[l - 1]:
                    l += 1
                while l < r and arr[r] == arr[r + 1]:
                    r -= 1
            elif s < 0:
                l += 1
            else:
                r -= 1

    return result


if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))

    triplets = solve(arr)
    if not triplets:
        print("NONE")
    else:
        for t in triplets:
            print(*t)
