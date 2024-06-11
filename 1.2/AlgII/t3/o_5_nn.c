#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define MAX 1000

int get_first_position(int aux[MAX]){
	return aux[0];
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
