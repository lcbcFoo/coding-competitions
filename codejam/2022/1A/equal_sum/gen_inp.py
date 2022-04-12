with open('inp.txt', 'w') as f:
    N = int(1e9)
    f.write(str(1) + '\n')
    f.write(str(100) + '\n')
    selected = set()
    import random
    for i in range(100):
        n = random.randint(1, N)
        while n in selected:
            n = random.randint(1, N)
        selected.add(n)
        f.write(str(n) + ' ')
    f.write('\n')
