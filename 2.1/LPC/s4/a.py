year = int(input())

while(1):
    year += 1
    found = 1
    num = []
    for e in str(year):
        if e in num:
            found = 0
            break
        num += e
    if found:
        break
print(year)
                
