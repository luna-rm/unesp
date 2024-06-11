#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

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
            return 1;
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
        return 0;
    }

    return -1;
}

void end(){
    system("cls");
    printf("Obrigada por usar o programa!!\n\n");
    rand_sleep(200, 400);
    printf("Feito por:\n");
    rand_sleep(200, 400);
    printf("- Bruno Ramalho Nascimento\n");
    rand_sleep(50, 100);
    printf("- Camila Cristina Silva\n");
    rand_sleep(50, 100);
    if(rand()%14 == 4){
        printf("- Luna Ricieri Marchi\n");
        rand_sleep(400, 600);
        system("cls");
        rand_sleep(50, 100);
        printf("Obrigada por usar o programa!!\n");
        printf("Feito por:\n");
        printf("- Bruno Ramalho Nascimento\n");
        printf("- Camila Cristina Silva\n");
        rand_sleep(50, 100);
        printf("- Pedro Ricieri Marchi\n");
    } else {
        printf("- Pedro Ricieri Marchi\n");
    }
    
    rand_sleep(500, 1000);
    exit(1);   
} 

void f_help(){
    FILE * arquivo = fopen("help_exp.txt", "rt");
    system("cls");
    
    while(!feof(arquivo)) {
        char caracter = getc(arquivo);
        if((caracter >= 65 && caracter <= 90) || (caracter >= 97 && caracter <= 122)){
            caracter += 4;
            if(caracter > 90 && caracter < 97){
                int aux = caracter - 91;
                caracter = 65 + aux;
            } else if(caracter > 122){
                int aux = caracter - 123;
                caracter = 97 + aux;
            }
        }
        printf ("%c",caracter);
    }

    printf("\n");    
    fclose(arquivo);
    press_any();
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

void go(int where, char old_buffer[1024]){
    system("cls");

    SYSTEMTIME st;

    GetLocalTime(&st);
    
    printf("%02d:%02d   :)\n", st.wHour, st.wMinute);      
    printf("----------------------------------------------\n\n");

    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    
    if(!d) {
        exit(1);
    }

    char buffer[1024];
    if(_getcwd(buffer, 1024) == NULL){
        exit(1);
    }

    rand_sleep(100, 200);
    printf("diretorio atual: ");
    rand_sleep(50, 100);
    printf("%s\n\n", buffer);
    rand_sleep(50, 100);

    buffer[0] = tolower(buffer[0]);

    if(strcmp(buffer, old_buffer)){
        where = 0;
    }

    int pos = 0;
    char file[30];
    while ((dir = readdir(d)) != NULL) {
        rand_sleep(25, 50);

        if(where == pos){
            printf(" >  ");
            strcpy(file, dir->d_name);
        } else {
            printf("    ");
        }
        printf("%s\n", dir->d_name);
        pos++;
    } 

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
        chdir("..");
    } else if(aux == 5){
        char command[1486];
        strcpy(command, buffer);
        strcat(command, "\\");
        strcat(command, file);
        _chdir(command);
    } else if(aux == 6){
        printf("\n\n\n  # qual o novo nome da pasta: ");
        char name[30];
        gets(name);
        for(unsigned int i = 0; i < sizeof(name); i++){
            if(name[i] == ' '){
                name[i] = '_';
            }
        }
        
        char command_old[1486];
        strcpy(command_old, buffer);
        strcat(command_old, "\\");
        strcat(command_old, file);
        
        char command_new[1486];
        strcpy(command_new, buffer);
        strcat(command_new, "\\");
        strcat(command_new, name);
        
        if(rename(command_old, command_new) != 0){
            printf("a");
        } 
    } else if(aux == 7){
        char command[1486];
        strcpy(command, buffer);
        strcat(command, "\\");
        strcat(command, file);
        if(!_rmdir(command)){
            remove(file);
        }     
    } else if(aux == 8){
        printf("\n\n\n  # qual o nome da pasta: ");
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
        int new_time;

        system("cls");
        rand_sleep(100, 200);
        printf("%02d:%02d   :)\n", st.wHour, st.wMinute);      
        printf("\n\n  # qual a nova hora: ");
        while(!scanf("%d", &new_time)){
            printf("\nhora invalida! tente novamente: ");
        }
        st.wHour = new_time;

        system("cls");
        rand_sleep(100, 200);
        printf("%02d:%02d   :)\n", st.wHour, st.wMinute);      
        printf("\n\n  # qual o novo min: ");
        while(!scanf("%d", &new_time)){
            printf("\nhora invalida! tente novamente: ");
        }
        st.wMinute = new_time;

        SetLocalTime(&st);
    } else if(aux == 1){
        f_help();
    } else if(aux == 0){
        end();
    }
    go(where, buffer);
}

int main() {
    srand(time(NULL));

    start();
    go(0, "queijo");

    return 0;
}
