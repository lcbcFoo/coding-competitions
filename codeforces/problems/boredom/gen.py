import random
N = int(1e5)

with open('test_' + str(N) + '.in', 'w') as f:
    f.write(str(N) + '\n')
    f.write(str(N) + '\n')
    writes = []
    for i in range(N):
        tmp = random.randint(1, N)
        writes.append(tmp)
    f.write(' '.join([str(x) for x in writes]))
    f.write('\n')

