#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 104

int main() {
    int mat[MAX][MAX];
    int order = -1;

    while(scanf("%d", &order) != EOF){
        for(int i = 0; i < order; i++){
            for(int j = 0; j < order; j++){
                mat[i][j] = 0;
                
                if(i == j){
                    mat[i][j] = 2;
                }
                if(i+j == order-1){
                    mat[i][j] = 3;
                }
            }
        }

        int aux = order/3;

        for(int i = aux; i < order-aux; i++){
            for(int j = aux; j < order-aux; j++){
                mat[i][j] = 1;
            }
        }

        mat[order/2][order/2] = 4;

        for(int i = 0; i < order; i++){
            for(int j = 0; j < order; j++){
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}
