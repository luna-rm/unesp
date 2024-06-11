n = int(input())

if n == 1:
    print(f'1')
elif n == 4:
    print(f'3 1 4 2')
elif n < 5:
    print(f'NO SOLUTION')
else:
    ans = ''
    for e in range(1, n+1, 2):
        ans += f'{e} '
    for e in range(2, n+1, 2):
        ans += f'{e} '    
    print(ans)