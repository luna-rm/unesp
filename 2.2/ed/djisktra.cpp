#include<bits/stdc++.h> 

using namespace std;

int main() {

    int grafo[5][5];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            int aux;
            scanf("%d", aux);
            grafo[i][j] = aux;
        }
    }

    int visited[5] = {0, 0, 0, 0, 0};
    int ans[5] = {0, 0, 0, 0, 0};
    int going[5] = {1, 2, 3, 4, 5};

    int from = 1;
    int to = 5;

    visited[from-1] = from;

    int sum = 10;
    while(sum != 0){
        

        for(int i = 0; i < 5; i++){
            if(grafo[from-1][i] != 0){
                if(!visited[i]){
                    if()
                }
            }
        }

        sum = 0;
        for(int i = 0; i < 5; i++){
            sum += going[i];
        }
    }

    return 0;
}