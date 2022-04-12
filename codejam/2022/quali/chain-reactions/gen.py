import random


N = 100000
Fi = int(1e9)

with open('input_' + str(N), 'w') as f:
    f.write('100\n')
    for t in range(100):
        n = random.randint(int(0.9) * N, N)
        f.write(str(n) + '\n')
        fis = [0] * n
        for i in range(n):
            fis[i] = random.randint(int(0.5) * Fi, Fi)
        f.write(' '.join([str(i) for i in fis]))
        f.write('\n')
        points_to = [0] * n
        for i in range(n):
            low = i + 2 if i + 2 <= n else n
            point = random.randint(low, n)
            if random.random() > 0.91 or point == i + 1:
                point = 0
            points_to[i] = point
        f.write(' '.join([str(i) for i in points_to]))
        f.write('\n')

