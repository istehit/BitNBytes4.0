# Brute Force Approach - convert to string, reverse it using slicing,
# convert back to int, and THEN check the 32-bit range. Overflow is only
# detected after the (potentially huge) integer has already been built,
# which is unsafe/inefficient for languages with fixed-width integers,
# and here is simulated with a manual character-by-character rebuild
# instead of using arithmetic operations.

INT_MIN, INT_MAX = -2**31, 2**31 - 1


def solve(n: int) -> int:
    sign = -1 if n < 0 else 1
    s = str(abs(n))

    reversed_s = ""
    for ch in s:
        reversed_s = ch + reversed_s   # O(len) rebuild every character -> O(len^2)

    # strip leading zeros (handled naturally by int(), but done explicitly here)
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
