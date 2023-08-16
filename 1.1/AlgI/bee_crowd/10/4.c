#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

int main() {
    
    double num;
    char sm;
    double t = 0;

    scanf(" %c", &sm);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%lf", &num);
            if(i>j){
                t += num;
            }
        }
    }

    if(sm == 'M'){
        t = t/(MAX*(MAX-1)/2);
    }    

    printf("%.1lf", t);

    return 0;
}
