#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

int main() {
/*      while(1){
        int a = getch();
    printf("%d", a);
    a = getch();
    printf("%d", a);
    } 
    
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
        system(command);     */

         SYSTEMTIME st;

    GetSystemTime(&st);

    st.wHour = 2;

    SetLocalTime(&st);

    return 0;
}
