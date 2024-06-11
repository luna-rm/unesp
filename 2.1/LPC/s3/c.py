import sys
rl = sys.stdin.readline
wr = sys.stdout.write

n, q = map(int, rl().split())
listn = list(map(int, rl().split()))
first = {}

for i in range(n):
    try:
        if first[listn[i]]:
            continue
    except:
        first[listn[i]] = i

for i in range(q):
    query = int(rl())
    try:
        wr(f'{first[query]}\n')
    except:
        wr(f'-1\n')