n = int(input())
while(n):
    train = list(range(1, n+1))
    print(train)
    train_final = list(map(int, input().split()))
    while(train_final):
        train_aux = []
        for i in range(len(train_final)):
            if train_final[i] != train[i]:
                train_aux = [train[i]] + train_aux
            else:
                train.pop(i)
                train_final.pop(i)
            print(train)
        for i in range(len(train_aux)):
            if train_aux[i] != train[i]:
                train.pop(i)
                train_aux.pop(i)
                i -= 1
                print(train)
    
        if train != None:
            print('Yes')
        else:
           print('No') 
        
        train_final = list(map(int, input().split()))
    print()
    
    n = input()