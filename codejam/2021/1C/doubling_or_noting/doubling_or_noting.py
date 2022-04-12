import pprint
NUM_A = 0
NUM_B = 0
LIMIT = 12
tested: dict = {}

def get_input():
    global NUM_A
    global NUM_B
    NUM_A, NUM_B = input().split(' ')
    global tested
    tested = {}

def size(a):
    size = len(str(a))
    print(size)
    return size

def doNot(x):
    a = list(x)
    for i in range(len(a)):
        if a[i] == '0':
            a[i] = '1'
        else:
            a[i] = '0'
    first_non_zero = False
    i = 0
    while first_non_zero == False and i < len(a):
        if a[i] == '1':
            first_non_zero = True
        else:
            i += 1
    if i == len(a):
        a = '0'
    else:
        a = ''.join(a[i:])
    # print(a)
    return a

def double_a(a):
    if a == '0':
        doublea = '0'
    else:
        doublea = a + '0'
    return doublea


def add_to_set(a, operation):
    tested[a] = [operation, '', LIMIT + 1]

def update_set(a, operation):
    tested[a][1] = operation

def update_best(a, best):
    if best == 'IMPOSSIBLE':
        best = LIMIT + 1
    if tested[a][2] > best:
        tested[a][2] = best
    return tested[a][2]

BEST = LIMIT + 1
def _solve(a, b, depth, last_moves):
    print(' ' * depth + '-------------------------------')
    print(' ' * depth + 'a: ' + str(a) + ', depth: ' + str(depth))
    pprint.pprint(tested)
    if depth > LIMIT:
        return LIMIT + 1
    if a == b:
        global BEST
        if len(last_moves) < BEST:
            BEST = len(last_moves)
        print('\n.-.-.-..-.-.-.-.')
        print(last_moves)
        print('.-.-.-..-.-.-.-.\n')
        return depth
    # print(a, b)
    if a in set(tested):
        if tested[a][2] < depth:
            return LIMIT
        else:
            update_best(a, depth)
        # if tested[a][1] == '':
        #     if tested[a][0] == 'double':
        #         update_set(a, 'not')
        #         nota = doNot(a)
        #         n = _solve(nota, b, depth + 1, [last_moves[1], 'not'])
        #         return update_best(a, n)
        #     else:
        #         update_set(a, 'double')
        #         doublea = double_a(a)
        #         d = _solve(doublea, b, depth + 1, [last_moves[1], 'double'])
        #         return update_best(a, d)

        # # Already tried to double and not this number
        # else:
        #     return tested[a][2]
    else:
        add_to_set(a, 'not')
        update_best(a, depth)

    last_moves.append(a)

    nota = doNot(a)
    n = _solve(nota, b, depth + 1, last_moves)
    update_best(a, n)
    if len(a) > 3 * len(b):
        return LIMIT + 1
    update_set(a, 'double')
    doublea = double_a(a)
    d = _solve(doublea, b, depth + 1, last_moves)
    update_best(a, d)
    return depth
    
def solve():
    global BEST
    _solve(NUM_A, NUM_B, 0, [])
    # print(tested)
    # print('\n***\n')
    if BEST > LIMIT + 1:
        print('IMPOSSIBLE')
    else:
        print(BEST)

def main():
    T = int(input())
    for t in range(T):
        get_input()
        print('Case #' + str(t + 1) + ': ', end='')
        solve()

main()
