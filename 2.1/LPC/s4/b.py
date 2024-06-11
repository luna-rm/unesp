t = int(input())

for _ in range(t):
    n = int(input())
    listn = list(map(int, input().split()))
    dictn = {}
    for i in range(len(listn)):
        try:
            dictn[listn[i]] += 1
        except:
            dictn[listn[i]] = 1
    val = [0, 0]
    for e in dictn:
        if val[1] < dictn[e]:
            val[1] = dictn[e]
            val[0] = e
    if val[1] != 1:
        ri = -1
        rj = 0
        for i in range(len(listn)):
            if listn[i] != val[0]:
                if ri == -1:
                    ri = i
                else:
                    rj = i
                    
        if ri == -1:
            ri = 0
            print(0)
        else:
            print(rj-ri+1) 
    else:   
        ri = 1
        rj = len(listn)-1
        print(rj-ri+1)
            