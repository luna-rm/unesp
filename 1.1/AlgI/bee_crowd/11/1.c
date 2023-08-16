#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1004

int main() {
    
    int n;
    char word[MAX];

    scanf("%d", &n);

    while(n){
        //printf("enter %d\n", n);

        fflush(stdin);
        fgets(word, MAX, stdin);

        int len = strlen(word)-1;
        
        for(int i = 0; i < len; i++){
            if((word[i] >= 'A' && word[i <= 'Z']) || (word[i] >= 'a' && word[i <= 'z'])){
                word[i] += 3;
            }
        }

        for(int i = 0; i < len/2; i++){
            int aux = word[i];
            word[i] = word[len-1-i];
            word[len-1-i] = aux;
        }

        int mid = len/2;
        if(len%2 == 1){
            mid++;
        }

        for(int i = len-mid; i < len; i++){
            word[i] -= 1;
        }

        printf("%s\n", word);
        n--;
    }

    return 0;
}
