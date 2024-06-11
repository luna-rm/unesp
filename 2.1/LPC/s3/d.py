n, q = map(int, input().split())
listn = list(map(int, input().split()))
dictn = {}

for i in range(len(listn)):
    try:
        dictn[listn[i]] += [i+1]
    except:
        dictn[listn[i]] = [i+1]

for _ in range(q):
    num, pos = map(int, input().split())
    try:
        print(dictn[num][pos-1])
    except:
        print("-1")