import sys


def solve(a, b):
    merged = a + b
    merged.sort()           

    total = len(merged)
    mid = total // 2

    if total % 2 == 1:
        return merged[mid]
    else:
        return (merged[mid - 1] + merged[mid]) / 2


def format_output(value):
    if isinstance(value, int) or value == int(value):
        return str(int(value))
    return f"{value:.1f}"


if __name__ == "__main__":
    data = sys.stdin.read().split()
    idx = 0
    n = int(data[idx]); idx += 1
    a = list(map(int, data[idx:idx + n])); idx += n
    m = int(data[idx]); idx += 1
    b = list(map(int, data[idx:idx + m])); idx += m

    result = solve(a, b)
    print(format_output(result))
