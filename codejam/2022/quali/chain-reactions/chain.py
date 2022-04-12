import copy
import sys

sys.setrecursionlimit(1050)

MAX_FUN = int(100000 * 1e9)

def get_input():
    global N
    global funs
    N = int(input())
    funs = [{'value': x,
        'points_to': -1,
        'revs_to': [],
        'used': False} for x in input().split(' ')]
    global used
    global points_to
    global revs_to
    global value

    connections = [int(x) for x in input().split(' ')]
    for idx, c in enumerate(connections):
        funs[idx]['points_to'] = c - 1
        if c != 0:
            funs[c - 1]['revs_to'].append(idx)
    # import pprint
    # pprint.pprint(funs)
    used = [x['used'] for x in funs]
    points_to = [x['points_to'] for x in funs]
    revs_to = [x['revs_to'] for x in funs]
    value = [int(x['value']) for x in funs]
    # import pprint
    # pprint.pprint(funs)

def find_best_trigger(e, depth = 0):
    # print('  ' * depth +  'finding best for: ' + str(e))
    if used[e]:
        # print('  ' * depth + 'returning')
        return 0, -1

    if revs_to[e] == []:
        # print('  ' * depth + 'returning')
        return value[e], e

    cost = MAX_FUN
    best_det = -1

    for i in revs_to[e]:
        tmp, det = find_best_trigger(i, depth + 1)
        if tmp < cost:
            cost = tmp
            best_det = det

    # print('  ' * depth + 'returning')
    if cost > value[e]:
        return cost, best_det
    else:
        return value[e], best_det

def detonate(trigger):
    global used
    i = trigger
    # print('detonating:')
    children = []
    while i != -1 and not used[i]:
        # print(i + 1)
        used[i] = True
        i = points_to[i]
        for c in revs_to[i]:
            if not used[i]:
                children.append(c)
    # print('done')
    return children

def solve_tree(root):
    global used
    # print(root)
    # print(used)
    if root == -1:
        return 0
    if used[root]:
        total = 0
        # for i in revs_to[root]:
        #     total += solve_tree(i)
        return total
    total = 0
    cost, best_trigger = find_best_trigger(root)
    if best_trigger != -1:
        children = detonate(best_trigger)
        total += cost
        # print(used)
        for i in children:
            total += solve_tree(i)
    # print(total)
    # print('-------------')
    
    return total


def solve():
    endlines = [i for i,x in enumerate(points_to) if x == -1]

    # print('\n---- debug ----\n')
    
    # print('revs')
    # print(revs_to)
    # print('points_to')
    # print(points_to)
    # print(endlines)
    total = 0
    for e in endlines:
        # print('root tree: ' + str(e + 1))
        # print('end: ' + str(e))
        total += solve_tree(e)
        # print(used)
    # print(used)
    print(total)

def main():
    T = int(input())
    for t in range(T):
        get_input()
        print('Case #' + str(t + 1) + ': ', end='')
        solve()

main()
