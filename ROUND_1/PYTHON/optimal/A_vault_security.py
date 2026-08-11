# Optimal Approach - O(log10 N) time, O(1) extra space (ignoring string conversion)
# Reverse digits arithmetically and compare with original.

def solve(n: int) -> str:
    if n < 0:
        return "NO"

    original = n
    reversed_num = 0
    while n > 0:
        reversed_num = reversed_num * 10 + n % 10
        n //= 10

    return "YES" if reversed_num == original else "NO"


if __name__ == "__main__":
    n = int(input())
    print(solve(n))
