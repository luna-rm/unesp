import sys
rl = sys.stdin.readline
wr = sys.stdout.write

def binary_search(arr, val, start, end):
    if start == end:
        if arr[start] > val:
            return start
        else:
            return start+1

    if start > end:
        return start
 
    mid = int((start+end)/2)
    if arr[mid] > val:
        return binary_search(arr, val, mid+1, end)
    elif arr[mid] < val:
        return binary_search(arr, val, start, mid-1)
    else:
        return mid

t = int(rl())

for _ in t:
    n, cows = map(int, rl().split())
    
    for _ in range(n):
        aux = int(rl())
        