#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <dirent.h>
#include <unistd.h>

#define HELP 59
#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27
#define C 99
#define R 114
#define D 100
#define H 104


void rand_sleep(int min, int max){
    int aux = (rand()%(max-min))+min;
    Sleep(aux);
}

void press_any(){
    printf("\npressione qualquer tecla para continuar..."); 
    getch();
}

int press_key(){
    int key = getch();

    if(key == 0){
        key = getch();
        if(key == HELP){
            return 0;
        }
    } else if(key == 224){
        key = getch();
        if(key == UP){
            return 2;
        } else if(key == DOWN){
            return 3;
        } else if(key == LEFT){
            return 4;
        } else if(key == RIGHT){
            return 5;
        }
    } else if(key == R){
        return 6;
    } else if(key == D){
        return 7;
    } else if(key == C){
        return 8;
    } else if(key == H){
        return 9;
    } else if(key == ESC){
        return 1;
    }

    return -1;

}

void start(){
    printf("--explorer-2.0--\n\n"); 

    rand_sleep(500, 1000);
    printf("voce sera redirecionado para uma pasta\n");
    rand_sleep(100, 200);
    printf("precione para:\n");
    rand_sleep(100, 200);
    printf("    <seta para cima> subir\n");
    rand_sleep(50, 100);
    printf("    <seta para baixo> descer\n");
    rand_sleep(50, 100);
    printf("    <seta para esquerda> voltar\n");
    rand_sleep(50, 100);
    printf("    <seta para direita> entrar na pasta\n");
    rand_sleep(50, 100);
    printf("    <c> criar pasta\n");
    rand_sleep(50, 100);
    printf("    <r> renomear\n");
    rand_sleep(50, 100);
    printf("    <d> excluir\n");
    rand_sleep(50, 100);
    printf("    <h> mudar horario do sistema\n");
    rand_sleep(50, 100);
    printf("    <esc> sair\n");
    rand_sleep(50, 100);
    printf("    <F1> ajuda\n");
    rand_sleep(1000, 2500);
    press_any();
}

void go(int where){
    system("cls");

    SYSTEMTIME st,lt;

    GetSystemTime(&st);
    //SetLocalTime(&st);
    
    GetLocalTime(&lt);

    printf("%02d:%02d:%02d - %02d/%02d/%02d   :)\n", lt.wHour, lt.wMinute, lt.wSecond, lt.wDay, lt.wMonth, lt.wYear);
    printf("----------------------------------------------\n\n");

    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    
    if(!d) {
        exit(1);
    }

    int pos = 0;
    char file[30];
    while ((dir = readdir(d)) != NULL) {
        rand_sleep(50, 75);

        if(where == pos){
            printf(" >  ");
            strcpy(file, dir->d_name);
        } else {
            printf("    ");
        }
        printf("%s\n", dir->d_name);
        pos++;
    } 

    //printf("\n\n\n%s", file);

    int aux = -1;
    while(aux == -1){
        aux = press_key();
    }
    pos--;
    if(aux == 2){
        where--;
        if(where < 0){
            where = pos;
        }
    } else if(aux == 3){
        where++;
        if(where > pos){
            where = 0;
        }
    } else if(aux == 4){
        where = 0;
        chdir("..");
    } else if(aux == 5){
        char command[60] = "cd ./";
        strcat(command, file);
        chdir(command);  
    } else if(aux == 6){
           
    } else if(aux == 7){
        where++;
        if(where > pos){
            where = 0;
        }
    } else if(aux == 8){
        printf("\n\n\n\n  > qual o nome da pasta: ");
        char name[30];
        gets(name);
        for(unsigned int i = 0; i < sizeof(name); i++){
            if(name[i] == ' '){
                name[i] = '_';
            }
        }
        char command[60] = "md ";
        strcat(command, name);
        system(command);        
    } else if(aux == 9){
        where++;
        if(where > pos){
            where = 0;
        }
    } else if(aux == 3){
        where++;
        if(where > pos){
            where = 0;
        }
    }



    if(aux != 0){
        go(where);
    }
}

int main() {
    srand(time(NULL));

    start();
    go(0);

    return 0;
}