#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main() {
    /* while(1){
        int a = getch();
    printf("%d", a);
    a = getch();
    printf("%d", a);
    } */
    
printf("\n\n\n\n  > qual o nome da pasta: ");
        char name[30];
        gets(name);
        for(int i = 0; i < sizeof(name); i++){
            if(name[i] == ' '){
                name[i] = '_';
            }
        }
        char command[60] = "md";
        strcat(command, name);
        system(command);    

    return 0;
}
