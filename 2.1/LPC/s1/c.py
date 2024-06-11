l, b, g = map(int, input().split())
bad = []
ans = g
for i in range(b):
    bad.append(int(input()))
for i in range(g):
    l += int(input())

for e in bad:
    if e <= l:
        l += -e
        ans += 1
    else:
        break

print(ans)
