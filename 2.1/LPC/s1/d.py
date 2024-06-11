b, s = map(int, input().split())
list_b = list(map(int, input().split()))

num = 0
for e in list_b:
    if e > num:
        if s % e == 0:
            num = e

print(f'{int(s/num)}')