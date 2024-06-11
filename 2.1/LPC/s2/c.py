n = int(input())

query = []
dir = 1
while(n):
    n -= 1
    what = list(input().split())
    if what[0] == 'back':
        if query:
            if dir:
                print(query.pop())
            else:
                print(query.pop(0))
        else:
            print('No job for Ada?')
    elif what[0] == 'front':
        if query:
            if dir:
                print(query.pop(0))
            else:
                print(query.pop())
        else:
            print('No job for Ada?')
    elif what[0] == 'reverse':
        if dir:
            dir = 0
        else:
            dir = 1
    elif what[0] == 'push_back':
        if dir:
            query += [int(what[1])]
        else:
            query = [int(what[1])] + query
    elif what[0] == 'toFront':
        if dir:
            query = [int(what[1])] + query
        else:
            query += [int(what[1])]
        