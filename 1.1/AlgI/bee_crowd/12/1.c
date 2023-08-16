#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {

    int n;
    scanf("%d", &n);

    while(n--){
        char str[4];
        fflush(stdin);
        gets(str);
        
        int num1 = (int) str[0] - '0';
        int num2 = (int) str[2] - '0';

        if(num1 == num2){
            printf("%d\n", num1*num2);
        } else {
            if(str[1] >= 'A' && str[1] <= 'Z'){
                printf("%d\n", num2-num1);
            } else {
                printf("%d\n", num2+num1);
            }
        }
    }

    return 0;
}
