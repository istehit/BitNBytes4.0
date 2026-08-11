def solve(s: str) -> int:
    val = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}

    subtract_pairs = {
        "IV": 4, "IX": 9,
        "XL": 40, "XC": 90,
        "CD": 400, "CM": 900,
    }

    total = 0
    i = 0
    remaining = s
    while i < len(remaining):
        pair = remaining[i:i + 2]
        if pair in subtract_pairs:
            total += subtract_pairs[pair]
            i += 2
        else:
            total += val[remaining[i]]
            i += 1

    return total

if __name__ == "__main__":
    s = input().strip()
    print(solve(s))
