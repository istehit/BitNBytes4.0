# Optimal Approach - O(n) single pass with lookahead comparison.

def solve(s: str) -> int:
    val = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
    total = 0
    n = len(s)
    for i in range(n):
        if i + 1 < n and val[s[i]] < val[s[i + 1]]:
            total -= val[s[i]]
        else:
            total += val[s[i]]
    return total


if __name__ == "__main__":
    s = input().strip()
    print(solve(s))
