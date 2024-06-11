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

n = int(input())

for _ in range(n):
    s, p = map(int, input().split())
    lists = list(map(int, input().split()))
    lists.sort(reverse=True)

    ans = 0
    while(p > 0):
        sold = lists.pop(0)
        p -= sold
        sold = int(sold/2)
        where = binary_search(lists, sold, 0, len(lists))
        lists = lists[:where] + [sold] + lists[where:len(lists)]
        ans += 1
        if lists[0] == 0:
            ans = -1
            print('Evacuate')
            break
            
    if ans != -1:
        print(ans)
        
            