from copy import deepcopy

def make_groups(group, ava, gt, avat):
    global best
    
    for i in range(len(ava)):
        group += [ava[i]]
        gt += group[-1]
        avat -= group[-1]
        diff = abs(gt-avat)
        print(f'{group} | {ava} \n {best} | {diff} | {gt} | {avat}')
        if best == None or best > diff:
            best = diff  
        sec_ava = []
        for e in ava:
            if e != ava[i]:
                sec_ava += [e]
                print(sec_ava)
        if len(ava):
            input()
            make_groups(deepcopy(group), deepcopy(sec_ava), deepcopy(gt), deepcopy(avat))
            
        

n = int(input())
listn = list(map(int, input().split()))

total = 0
for e in listn:
    total += e
best = None
make_groups([], listn, 0, total)
print(best)