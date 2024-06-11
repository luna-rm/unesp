from copy import deepcopy
def make_groups(group, ava, groupt, avat):
    for e in ava:
        group += [e]
        groupt += group[-1]
        avat -= group[-1]
        print(f'{groupt} | {group}')
        print(f'{avat} | {ava} \n')
        new_sec = []
        for e2 in ava:
            if e != e2:
                new_sec += [e2]
        new_group = deepcopy(group)
        return make_groups(deepcopy(new_group), deepcopy(new_sec), deepcopy(groupt), deepcopy(avat))
    print('aa')
    input()

n = int(input())
listn = list(map(int, input().split()))

total = 0
for e in listn:
    total += e
best = None
make_groups([], listn, 0, total)
print(best)