#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 101

int main() {
    
    int mat[MAX][MAX];
    int order = -1;

    scanf("%d", &order);

    while(order != 0){
        int init = 0;
        
        for(int i = init; i < order; i++){
            for(int j = init; j < order; j++){               
                mat[i][j] = (int) pow(2.0, (double) (i+j)); 
            }
        }

        int aux = 1, num = mat[order-1][order-1];
        while(num >= 10){
            num = num / 10;
            aux++;
        }

        for(int i = 0; i < order; i++){
            printf("%*d", aux, mat[i][0]);
            
            for(int j = 1; j < order; j++){
                printf("%*d", aux+1, mat[i][j]); 
            }
            printf("\n");
        }

        printf("\n");

        scanf("%d", &order);
    }

    return 0;
}
