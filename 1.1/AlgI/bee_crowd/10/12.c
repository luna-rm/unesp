#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

int main() {
    
    int mat[MAX][MAX];
    int order = -1;

    scanf("%d", &order);

    while(order != 0){
        int init = 0;
        
        for(int i = init; i < order; i++){
            for(int j = init; j < order; j++){
                mat[i][j] = (i+1)+(j+1)+1; 
            }
        }
        
        while(init < order){
            for(int i = init; i < order; i++){
                for(int j = init; j < order; j++){
                    mat[i][j] -= 2; 
                }
            }
            init++;
        }

        for(int i = 0; i < order; i++){
            printf("%3d", mat[i][0]);
            for(int j = 1; j < order; j++){
                printf(" %3d", mat[i][j]); 
            }
            printf("\n");
        }

        printf("\n");

        scanf("%d", &order);
    }

    return 0;
}
