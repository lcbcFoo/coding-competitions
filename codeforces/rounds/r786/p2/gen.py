n = 650
with open('t1.in', 'w') as f:
    f.write(str(n) + '\n')
    for i in range(n):
        f.write(str(i + 1) + '\n')
