INT_MIN, INT_MAX = -2**31, 2**31 - 1


def solve(n: int) -> int:
    sign = -1 if n < 0 else 1
    s = str(abs(n))

    reversed_s = ""
    for ch in s:
        reversed_s = ch + reversed_s  

    idx = 0
    while idx < len(reversed_s) - 1 and reversed_s[idx] == '0':
        idx += 1
    reversed_s = reversed_s[idx:]

    rev = sign * int(reversed_s)

    if rev < INT_MIN or rev > INT_MAX:
        return 0
    return rev


if __name__ == "__main__":
    n = int(input())
    print(solve(n))
