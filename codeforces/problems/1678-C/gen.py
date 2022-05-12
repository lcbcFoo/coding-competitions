T = 5
N = 1000
import numpy

with open('test.inp', 'w') as f:
    f.write(str(T) + '\n')
    for _ in range(T):
        f.write(str(N) + '\n')
        x = numpy.random.permutation(numpy.arange(N))
        s = ' '.join([str(a) for a in x])
        f.write(s + '\n')
