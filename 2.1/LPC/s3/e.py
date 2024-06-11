import sys
rl = sys.stdin.readline
wr = sys.stdout.write

n = int(rl())

#triang = []

for _ in range(n):
    q = int(rl())    
    i = 0
    total = 0
    while(1):
        i+=1
        total += i
        #triang += [total]
        if total > q:
            wr(f'{i-1}\n')
            break

