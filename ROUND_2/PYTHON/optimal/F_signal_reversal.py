INT_MIN, INT_MAX = -2**31, 2**31 - 1


def solve(n: int) -> int:
    sign = -1 if n < 0 else 1
    n = abs(n)

    rev = 0
    while n:
        digit = n % 10
        n //= 10


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
