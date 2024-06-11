#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    FILE * arq;
    arq = fopen("tx.txt", "w+");

    if(arq){
        char str[100];
        gets(str);
        while(strlen(str)){
            for(int i = 0; i < strlen(str); i++){
                fputc(str[i], arq);
            }
            fputc('\n', arq);
            gets(str);
        }
    }

    fclose(arq);

    return 0;
}
