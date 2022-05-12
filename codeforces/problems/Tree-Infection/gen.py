N = 200000

import random
with open('inp.txt', 'w') as f:
    f.write(str(1) + '\n')
    f.write(str(N) + '\n')
    for i in range(N):
        t = random.randint(1, N - 2)
        f.write(str(t) + ' ')
    f.write('\n')


