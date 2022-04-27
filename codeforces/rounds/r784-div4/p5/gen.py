N = int(1e5)
import random

with open('inp.in', 'w') as f:
    f.write('1\n')
    f.write(str(N) + '\n')
    for i in range(N):
        s = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k']
        a = s[random.randint(0, len(s) - 1)]
        b = s[random.randint(0, len(s) - 1)]
        f.write(a + b + '\n')

