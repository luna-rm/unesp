n = input()
listn = list(map(int, input().split()))

ansr = {}
bigger = 1
for e in listn:
    if e in ansr:
        ansr[e] += 1
        if ansr[e] > bigger:
            bigger = ansr[e]
    else:
        ansr[e] = 1
        
print(f'{bigger} {len(ansr)}')
