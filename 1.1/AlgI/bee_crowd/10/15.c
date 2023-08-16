#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

int main() {
    int att = -1;
    while(scanf("%d", &att) != EOF){
        int marcos = -1, leo = -1;
        int deck_marcos[MAX][MAX], deck_leo[MAX][MAX];
        
        scanf("%d", &marcos);
        scanf("%d", &leo);

        for(int i = 0; i < marcos; i++){
            for(int j = 0; j < att; j++){
                scanf("%d", &deck_marcos[i][j]);
            }
        }

        for(int i = 0; i < leo; i++){
            for(int j = 0; j < att; j++){
                scanf("%d", &deck_leo[i][j]);
            }
        }

        int w_marcos = -1, w_leo = -1;
        int w_att = -1;

        scanf("%d", &w_marcos);
        scanf("%d", &w_leo);
        scanf("%d", &w_att);

        if(deck_marcos[w_marcos-1][w_att-1] > deck_leo[w_leo-1][w_att-1]){
            printf("Marcos\n");
        } else if(deck_marcos[w_marcos-1][w_att-1] < deck_leo[w_leo-1][w_att-1]){
            printf("Leonardo\n");
        } else {
            printf("Empate\n");
        }
    }

    return 0;

}
