import copy

NEEDED = int(1e6)
cs = []
ms = [] 
ys = []
ks = []
COLORS = []

def get_input():
    global OWN_TEST_CASE
    global cs
    global ms
    global ys
    global ks
    global COLORS
    cs = []
    ms = []
    ys = []
    ks = []
    COLORS = []
    for _ in range(3):
        c, m, y, k = [int(x) for x in input().split(' ')]
        cs.append(c)
        ms.append(m)
        ys.append(y)
        ks.append(k)
    # cs = sorted(cs)
    # ms = sorted(ms)
    # ys = sorted(ys)
    # ks = sorted(ks)
    COLORS.append(min(cs))
    COLORS.append(min(ms))
    COLORS.append(min(ys))
    COLORS.append(min(ks))

def solve():
    own = NEEDED
    used = []
    for color in COLORS:
        if own - color <= 0:
            use = own
            own = 0
        else:
            use = color
            own -= color
        used.append(use)
        if own == 0:
            i = len(used)
            while i < 4:
                used.append(0)
                i += 1
            break
    if own > 0:
        print('IMPOSSIBLE')
    else:
        print(' '.join([str(x) for x in used]))

def main():
    T = int(input())
    for t in range(T):
        get_input()
        print('Case #' + str(t + 1) + ': ', end='')
        solve()

main()
