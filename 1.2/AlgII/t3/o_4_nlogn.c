#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 10

void print_vet(int vet[], int size) {
    for (int i = 0; i < size; i++){
        printf("%d ", vet[i]);
    }

    printf("\n");
}

void merge(int vet[], int sub_left, int sub_mid, int sub_right) {
    print_vet(vet, sub_right-sub_left);
    
    int n1 = sub_mid - sub_left + 1;
    int n2 = sub_right - sub_mid;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++){
        L[i] = vet[sub_left + i];
    }
        
    for (int j = 0; j < n2; j++){
        M[j] = vet[sub_mid + 1 + j];
    }
        
    int i, j, k;
    i = 0;
    j = 0;
    k = sub_left;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            vet[k] = L[i];
            i++;
        } else {
            vet[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vet[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vet[k] = M[j];
        j++;
        k++;
    }
}

void merge_sort(int vet[MAX], int left, int right) {
    if (left >= right) {
        return;
    }

    int mid = left + (right - left) / 2;

    merge_sort(vet, left, mid);
    merge_sort(vet, mid + 1, right);

    merge(vet, left, mid, right);
}

int main() {
    srand(time(NULL));

    int vet[MAX];
    for(int i = 0; i < MAX; i++){
        vet[i] = rand() % MAX;
    }

    printf("before:\n");
    print_vet(vet, MAX);
    
    merge_sort(vet, 0, MAX);

    printf("\nafter:\n");
    print_vet(vet, MAX);

    return 0;
}
