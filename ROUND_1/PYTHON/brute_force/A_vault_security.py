# Brute Force Approach - build the reversed string character by character
# using string concatenation (O(len^2) due to repeated string copies),
# then compare with the original string.

def solve(n: int) -> str:
    if n < 0:
        return "NO"

    s = str(n)
    reversed_s = ""
    for i in range(len(s) - 1, -1, -1):
        reversed_s = reversed_s + s[i]   # O(len) copy every iteration -> O(len^2) total

    return "YES" if reversed_s == s else "NO"


if __name__ == "__main__":
    n = int(input())
    print(solve(n))
