import sys
sys.setrecursionlimit(10000)

move_count = 0

def hanoi(n, source, auxiliary, target):
    global move_count
    if n == 0:
        return
    hanoi(n - 1, source, target, auxiliary)
    move_count += 1                 
    hanoi(n - 1, auxiliary, source, target)


def solve(n: int) -> int:
    global move_count
    move_count = 0
    hanoi(n, 'A', 'B', 'C')
    return move_count


if __name__ == "__main__":
    n = int(input())
    print(solve(n))
