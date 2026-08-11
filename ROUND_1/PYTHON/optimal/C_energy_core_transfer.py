def solve(n: int) -> int:
    return (1 << n) - 1

if __name__ == "__main__":
    n = int(input())
    print(solve(n))
