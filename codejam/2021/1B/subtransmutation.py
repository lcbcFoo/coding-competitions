import copy

A = 0
B = 0
N = 0
OWN_TEST_CASE = []
HAVE = []

def get_input():
    global A
    global B
    global N
    global OWN_TEST_CASE
    N, A, B = [int(x) for x in input().split(' ')]
    tmp = input().split(' ')
    OWN_TEST_CASE = [int(x) for x in tmp]

def empty(own):
    a = [x for x in own if x != 0]
    return len(a) == 0

def transmute(i, amount):
    global A
    global B
    result = []
    if i - A >= 0:
        result.append([i - A, amount])
    if i - B >= 0:
        result.append([i - B, amount])
    return result

def _solve(have, own):
    # print('----------------------------------')
    # print(have)
    # print(own)
    if empty(own):
        return True
    if empty(have):
        return False
    for i in range(len(own)):
        if own[i] == 0:
            pass
        elif have[i] >= own[i]:
            have[i] -= own[i]
            own[i] = 0
        else:
            own[i] -= have[i]
            have[i] = 0
    
    for i in range(len(have)):
        if have[i]:
            result = transmute(i, have[i])
            have[i] = 0
            for j, v in result:
                have[j] += v
    
    return _solve(have, own)

def solve():
    total_required = sum(OWN_TEST_CASE)
    i = len(OWN_TEST_CASE) + 1
    limit = 403
    found = False
    while not found and i  < limit:
        # print('\n===============')
        # print('try i = ' + str(i))
        # print('')
        have = [0] * i
        have[i - 1] = 1
        own = copy.copy(OWN_TEST_CASE)
        found = _solve(have, own)
        if found:
            print(i)
            found = True
        else:
            i += 1
    if not found:
        print('IMPOSSIBLE')

def main():
    T = int(input())
    for t in range(T):
        get_input()
        print('Case #' + str(t + 1) + ': ', end='')
        solve()

main()
