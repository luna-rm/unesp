import sys
rl = sys.stdin.readline
wr = sys.stdout.write

n = int(rl())
for _ in range(n):
    n_ = rl()
    listn = list(map(int, rl().split()))
    listn.sort()
    ans = 0
    for i in range(len(listn)-1):
        ans += listn[i+1] - listn[i]

    print(f'{ans}')    

