import sys
rl = sys.stdin.readline
wr = sys.stdout.write

n = int(rl())

for _ in range(n):
    li, one, two = map(int, rl().split())
    
    if li == 1:
        print(f'{one}')
        continue
    
    if one*2 < two:
        print(f'{int(li*one)}')
        continue
    
    if li % 2 == 0:
        print(f'{int(li/2*two)}')
        continue
    
    print(f'{int((((li-1)/2)*two) + one)}')