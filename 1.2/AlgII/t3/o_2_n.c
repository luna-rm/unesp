#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 1000

void find_element(int vet[MAX], int value){
    for(int i = 0; i < MAX; i++){
        if(vet[i] == value){
            printf("valor na posicao: %d\n\n", i);
            break;
        }
    }
}


int main() {
    srand(time(NULL));

    int arr[MAX];
    for(int i = 0; i < MAX; i++){
        arr[i] = i;
    }

    printf("%d", get_first_position(arr));

    return 0;
}
