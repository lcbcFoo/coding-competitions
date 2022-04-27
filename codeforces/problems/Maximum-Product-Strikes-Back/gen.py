N = int(2 * 1e5)
import random
with open('test_' + str(N) + '.in', 'w') as f:
    f.write('1\n')
    f.write(str(N) + '\n')
    for i in range(N):
        a = random.randint(-2, 2)
        f.write(str(a) + ' ')
    f.write('\n')
