MAX = 32768
with open('inp.txt', 'w') as f:
    f.write(str(MAX) + '\n')
    for i in range(MAX):
        f.write(str(i) + ' ')
    f.write('\n')
