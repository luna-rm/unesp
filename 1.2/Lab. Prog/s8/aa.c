#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int fat(int n){
    if(n <= 1){
        return 1;
    }
    return n*fat(n-1);
}


int main() {
    //cout << fat(3);
    char a = getchar();
    printf("%c", a);

    return 0;
}