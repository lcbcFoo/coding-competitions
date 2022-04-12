T = int(1e4)
import random

MAX = int(1e8)

with open('big.in', 'w') as f:
    f.write(str(T) + '\n')
    for i in range(T):
        f.write(str(random.randint(1, MAX)) + ' ' + str(random.randint(1, MAX)) + '\n')


