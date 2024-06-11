#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 1000

int get_first_position(int aux[MAX]){
	return aux[0];
}	

void find_element(int vet[MAX], int value){
    for(int i = 0; i < MAX; i++){
        if(vet[i] == value){
            printf("valor na posicao: %d\n\n", i);
            break;
        }
    }
}


// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {

  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// Driver program
int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  printf("Sorted array: \n");
  printArray(arr, size);
}

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

    //printf("%d", get_first_position(arr));
    //find_element(arr, 667);
    bin_search(arr, 667, 0, 1000);

    return 0;
}
