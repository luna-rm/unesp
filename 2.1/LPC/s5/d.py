import sys
rl = sys.stdin.readline
wr = sys.stdout.write

_, _, diff = map(int, rl().split())
ap = list(map(int, rl().split()))
mor = list(map(int, rl().split()))

ap.sort()
mor.sort()

ans = 0

for e in mor:
    while(ap):
        a = ap[0]
        print(a)
        if a > e + diff:
            break
        if abs(a - e) <= diff:
            ans += 1
            ap.remove(a)
            break
        ap.remove(a)
        
print(ans)
            
            
