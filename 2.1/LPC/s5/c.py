import sys
rl = sys.stdin.readline
wr = sys.stdout.write

n = int(rl())

for _ in range(n):
    n2 = int(rl())
    activ = []

    for _ in range(n2):
        start, end = map(int, rl().split())
        activ += [[end, start]]
    
    activ.sort()
    
    ans = 0
    mini = 0
    for e in activ:
        if e[1] >= mini:
            ans+=1
            mini = e[0]
    
    print(ans)
    rl()
    
            
