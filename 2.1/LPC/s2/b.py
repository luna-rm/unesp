n = input()
listn = list(map(int, input().split()))

listn.sort()

ans = 0
while(listn):
    e = listn.pop()
    e2 = listn.pop()
    
    ans += e-e2

print(ans)
    
    