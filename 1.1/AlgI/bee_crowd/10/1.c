#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 3

int main() {
    
    int l;
    double num;
    char sm;
    double t = 0;

    scanf("%d %c", &l, &sm);

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            scanf("%lf", &num);
            if(i == l){
                t += num;
            }
        }
    }

    if(sm == 'M'){
        t = t/MAX;
    }    

    printf("%.1lf", t);

    return 0;
}
