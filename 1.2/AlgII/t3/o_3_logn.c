#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 1000

void bin_search(int vet[MAX], int value, int right, int left){
    int mid = right + left;
    mid = mid/2;

    if(vet[mid] == value){
        printf("valor na posicao: %d\n\n", mid);
        return;
    }

    if(vet[mid] > value){
        return bin_search(vet, value, right, mid+1);
    }

    return bin_search(vet, value, mid-1, left);
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
