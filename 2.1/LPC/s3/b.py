n, travel = map(int, input().split())
time = 240 - travel
ans = 0

for i in range(1, n+1):
    if time >= 5*i:
        time-=5*i
        ans += 1

print(ans)
        