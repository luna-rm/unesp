n, h = map(int, input().split())
rides = list(map(int, input().split()))

ans = 0

for e in rides:
    if e <= h:
        ans += 1

print(ans)