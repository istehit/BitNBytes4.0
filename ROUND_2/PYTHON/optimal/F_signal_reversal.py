# Optimal Approach - O(log10 N) time, O(1) space.
# Reverse digits arithmetically one at a time, checking for 32-bit
# overflow BEFORE it happens (no big-int intermediate values needed).

INT_MIN, INT_MAX = -2**31, 2**31 - 1


def solve(n: int) -> int:
    sign = -1 if n < 0 else 1
    n = abs(n)

    rev = 0
    while n:
        digit = n % 10
        n //= 10

        # Overflow check before updating rev
        if rev > (INT_MAX - digit) // 10:
            return 0

        rev = rev * 10 + digit

    rev *= sign
    if rev < INT_MIN or rev > INT_MAX:
        return 0
    return rev


if __name__ == "__main__":
    n = int(input())
    print(solve(n))
