import copy
import numpy as np
import math
import random

N = 0
K = 0
t = 0

graph = {}
tested: set = set()
last_chosen = 0
done = False

def get_input(t = False, lesser=False):
    global graph
    room, ps = [int(x) for x in input().split(' ')]

    if lesser:
        return room, ps

    if t and room not in tested:
        tested.add(room)

    if room not in graph.keys():
        graph[room] = {'pass' : ps}
        graph[room].update({'known' : 0})
        adjs = set()
        graph[room].update({'adj' : adjs})

    return room, ps

def update_adjs(room, ps, prev):
    global graph
    if prev not in graph[room]['adj']:
        graph[room]['adj'].add(prev)
        graph[room]['known'] += 1

    if room not in graph[prev]['adj']:
        graph[prev]['adj'].add(room)
        graph[prev]['known'] += 1

def choose_next():
    global last_chosen
    i = random.randint(1, N)
    tries = 0
    while i in tested and tries < 50 * math.log10(N):
        i = random.randint(1, N)
        tries += 1
    last_chosen = i

    # with open('log_' + str(t), 'a') as f:
    #     f.write('T: ' + str(i) + '\n')

    tested.add(i)
    return i

rng = np.random.default_rng(0X1287721)
def calculate():
    global graph
    tot = 0
    median = 0
    for idx, k in enumerate(graph.keys()):
        v = graph[k]
        tot += v['pass']
    for t in tested:
        v = graph[t]['pass']
        median += v
    tot /=2
    if N > K:
        median = (median / 2) / len(tested)
        num_tested = len(tested)
        estimate = tot + median * (N - len(graph.keys()))
        # mith open('log_' + str(t), 'a') as f:
        #     f.write(str(tot) + '\n')
        #     f.write(str(median) + '\n')
        #     f.write(str(std) + '\n')
        #     f.write(str(factor) + '\n')
        #     f.write(str(num_tested) + '\n')
        #     f.write(str(estimate) + '\n')
    else:
        estimate = math.ceil(tot)


    return int(estimate)

def solve():
    
    if K >= N:
        room, ps = get_input(lesser=True)
        s = 0
        for i in range(N):
            print('T ' + str(i + 1))
            room, ps = get_input(lesser=True)
            s += ps

        print('E ' + str(int(s / 2)))
        return

    global graph
    command = 'W'
    nxt = 1
    prev, _ = get_input()

    for round in range(K):
        print(command)
        room, ps = get_input(command[0] == 'T')
        if command == 'W':
            update_adjs(room, ps, prev)
            nxt = choose_next()
            if nxt == -1:
                break
            command = 'T ' + str(nxt)
        else:
            command = 'W'

        prev = room

    estimate = calculate()
    print('E ' + str(estimate))

def main():
    T = int(input())
    global t

    from datetime import datetime
    random.seed(0xA0B2C3F9)
    for t in range(T):
        global N
        global K
        global graph
        global tested
        global last_chosen
        global done
        done = False
        tested = set()
        last_chosen = 0
        graph = {}
        N, K = [int(x) for x in input().split(' ')]
        # with open('log_' + str(t), 'w') as f:
        #     f.write('t: ' + str(t) + '\n')
        #     f.write('N: ' + str(N) + '\n')
        #     f.write('K: ' + str(K) + '\n')
        solve()

main()
