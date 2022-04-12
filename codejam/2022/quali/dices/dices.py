import copy

N = 1e6
dices = []

def get_input():
    global N
    global dices
    N = int(input())
    dices = [int(x) for x in input().split(' ')]

def solve():
    global N
    global dices

    dices = sorted(dices)
    used = 0
    for i in range(len(dices)):
        if dices[i] >= used + 1:
            used += 1

    print(used)

def main():
    T = int(input())
    for t in range(T):
        get_input()
        print('Case #' + str(t + 1) + ': ', end='')
        solve()

main()
