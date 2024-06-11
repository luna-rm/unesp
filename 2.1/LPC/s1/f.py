import copy
def calc_dist(a, b):
    return (abs(a[0]-b[0])**abs(a[0]-b[0]) + abs(a[1]-b[1])**abs(a[1]-b[1]))/100

def draw(color, colorha):
    for e in ha:
        for i in range(w):
            for j in range(l):
                nmap[i][j] = 0
        #print(e)
        fill_shortest_path(e, nmap, red, color, colorha, None, 0)
        """ for i in range(w):
            for j in range(l):
                print(f' {color[i][j]}', end='')
            print()
        print() """
        #input()
    for i in range(w):
            for j in range(l):
                nmap[i][j] = 0
    going_crazy = 1
    while(going_crazy):
        going_crazy = go_again(colorha, nmap, color)
    
def fill_shortest_path(start, nmap, map, alter, colorha, new_colorha, have_error):
    neighbours = [ [-1,0], [1,0], [0,-1], [0,1] ]
    queue = [start]
    visited = []
    
    while queue:
        cur_pos = queue.pop(0)
        visited += [cur_pos]
        for neighbour in neighbours:
            aux = [neighbour[0] + cur_pos[0], neighbour[1] + cur_pos[1]]
            if aux[0] < 0 or aux[1] < 0 or aux[0] >= w or aux[1] >= l:
                continue                     
            if map[aux[0]][aux[1]] == '#' and purple[aux[0]][aux[1]] != '#' and alter[aux[0]][aux[1]] != '#':
                continue
            if aux not in visited and aux not in queue:
                nmap[aux[0]][aux[1]] = nmap[cur_pos[0]][cur_pos[1]] + 1
                queue += [[aux[0], aux[1]]]
                if alter[aux[0]][aux[1]] == '#' and aux != start:
                    if have_error and aux not in new_colorha:
                        continue
                    """ for i in range(w):
                        for j in range(l):
                            print(f' {nmap[i][j]}', end='')
                        print() 
                    print() 
                    print(aux) """
                    backtrack(start, aux, visited, nmap, map, alter, colorha)
                    return

def backtrack(start, goal, visited, nmap, map, alter, colorha):
    neighbours = [ [-1,0], [1,0], [0,-1], [0,1] ]
    cur_pos = goal
    while nmap[cur_pos[0]][cur_pos[1]] != 0:
        small = []
        for neighbour in neighbours:
            aux = [neighbour[0] + cur_pos[0], neighbour[1] + cur_pos[1]]
            if aux[0] < 0 or aux[1] < 0 or aux[0] >= w or aux[1] >= l:
                continue
            if aux not in visited:
                continue
            if map[aux[0]][aux[1]] != '#' or aux == start:
                if small == []: 
                    small = [aux, nmap[aux[0]][aux[1]]]
                if nmap[aux[0]][aux[1]] < small[1]:
                    small[0] = aux
                    small[1] = nmap[aux[0]][aux[1]]
        #print(f'SMAKDMO {small}')
        try:
            alter[small[0][0]][small[0][1]] = '#'
        except:
            #print(small)
            return
        cur_pos = small[0]
        if small[0] not in colorha:
            colorha += [small[0]]
        """ print(f'c {cur_pos} |s {small[0]} {small[1]}')
        for i in range(w):
            for j in range(l):
                print(f' {alter[i][j]}', end='')
            print()
        print() """

def go_again(colorha, nmap, alter):
    neighbours = [ [-1,0], [1,0], [0,-1], [0,1] ]
    new_colorha = colorha
    cur_pos = new_colorha.pop(0)
    while(new_colorha):
        """ print(new_colorha)
        print(cur_pos)
        for i in range(w):
            for j in range(l):
                print(f' {alter[i][j]}', end='')
            print()
        print() """
        error = 1
        for neighbour in neighbours:
            aux = [neighbour[0] + cur_pos[0], neighbour[1] + cur_pos[1]]
            if aux in new_colorha:
                cur_pos = aux
                new_colorha.remove(aux)
                error = 0
                continue
        if error:
            #print("GO AGAIN!!!!")
            for i in range(w):
                for j in range(l):
                    nmap[i][j] = 0
            fill_shortest_path(cur_pos, nmap, red, alter, colorha, new_colorha, 1)   
            return 1   
        #input()
    return 0


w, l = map(int, input().split())
purple = []

for i in range(w):
    purple += [list(input())]
    
red = copy.deepcopy(purple)
blue = copy.deepcopy(purple)
nmap = []
ha = []

for i in range(w):
    small = []
    fake_map_sm = [] 
    for j in range(l):
        if purple[i][j] == "#":
            ha += [[i, j]]
        small += [0]
    nmap += [small]
#print(nmap)

draw(red, copy.deepcopy(ha))
#print("BLUEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE/a")
draw(blue, copy.deepcopy(ha))

#print('\n\n')
for i in range(w):
    for j in range(l):
        print(f'{red[i][j]}', end='')
    print()
print()
for i in range(w):
    for j in range(l):
        print(f'{blue[i][j]}', end='')
    print()

