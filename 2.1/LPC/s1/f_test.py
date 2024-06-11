map = [[[0, '.'],[0, '#'],[0, '#'],[0, '#'],[0, '.'],[0, '.'],[0, '.']],
       [[0, '.'],[0, '#'],[0, '.'],[0, '.'],[0, '.'],[0, '.'],[0, '.']],
       [[0, '.'],[0, '#'],[0, '.'],[0, '#'],[0, '.'],[0, '#'],[0, '.']],
       [[0, '.'],[0, '.'],[0, '.'],[0, '#'],[0, '.'],[0, '.'],[0, '.']],
       [[0, '.'],[0, '#'],[0, '#'],[0, '#'],[0, '#'],[0, '.'],[0, '#']],
       [[0, '.'],[0, '#'],[0, '.'],[0, '.'],[0, '.'],[0, '.'],[0, '.']],
       [[0, '.'],[0, '.'],[0, '.'],[0, '#'],[0, '.'],[0, '.'],[0, '.']]]

nmap = []
for line in map:
    small = []
    for e in line:
        small += [e[0]]
    nmap += [small]

def fill_shortest_path(start, goal, nmap):
    neighbours = [ [-1,0], [1,0], [0,-1], [0,1] ]
    queue = [start]
    visited = []
    
    while queue:
        cur_pos = queue.pop(0)
        visited += [cur_pos]
        for neighbour in neighbours:
            aux = [neighbour[0] + cur_pos[0], neighbour[1] + cur_pos[1]]
            if aux[0] < 0 or aux[1] < 0 or aux[0] > 6 or aux[1] > 6:
                continue
            if map[aux[0]][aux[1]][1] != '#':
                if aux not in visited and aux not in queue:
                    nmap[aux[0]][aux[1]] = nmap[cur_pos[0]][cur_pos[1]] + 1
                    queue += [[aux[0], aux[1]]]
                    if aux == goal:
                        backtrack(goal, visited, nmap, map)
                        return

def backtrack(goal, visited, nmap, map):
    neighbours = [ [-1,0], [1,0], [0,-1], [0,1] ]
    path = [goal]
    cur_pos = goal
    while nmap[cur_pos[0]][cur_pos[1]] != 0:
        small = [[10, 10], 1000]
        for neighbour in neighbours:
            aux = [neighbour[0] + cur_pos[0], neighbour[1] + cur_pos[1]]
            if aux[0] < 0 or aux[1] < 0 or aux[0] > 6 or aux[1] > 6:
                continue
            if aux not in visited:
                continue
            if map[aux[0]][aux[1]][1] != '#':
                if nmap[aux[0]][aux[1]] < small[1]:
                    small[0] = aux
                    small[1] = nmap[aux[0]][aux[1]]
        path += [small[0]]
        cur_pos = small[0]
        map[small[0][0]][small[0][1]][1] = '-'
        print(f'c {cur_pos} |s {small[0]} {small[1]}| p {path}')

start = [0,0]
goal = [4,5]
map[start[0]][start[1]][1] = 'o'
map[goal[0]][goal[1]][1] = 'x'
for i in range(len(nmap)):
    for j in range(len(line)):
        if(map[i][j][1] == '#'):
            print(" #", end='')
        else:
            print(f' {map[i][j][1]}', end='')
    print()
fill_shortest_path(start, goal, nmap)
for i in range(len(nmap)):
    for j in range(len(line)):
        if(map[i][j][1] == '#'):
            print(" #", end='')
        else:
            print(f' {nmap[i][j]}', end='')
    print()
print()

map[start[0]][start[1]][1] = 'o'
map[goal[0]][goal[1]][1] = 'x'
for i in range(len(nmap)):
    for j in range(len(line)):
        if(map[i][j][1] == '#'):
            print(" #", end='')
        else:
            print(f' {map[i][j][1]}', end='')
    print()