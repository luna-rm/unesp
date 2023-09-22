#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

void rand_sleep(int min, int max){
    int aux = (rand()%(max-min))+min;
    Sleep(aux);
}

void bold(int status) {
    static const char *seq[] = {"\x1b[0m", "\x1b[1m"};
    printf("%s", seq[!!status]);
}

void italic(int status) {
    static const char *seq[] = {"\x1b[0m", "\x1b[3m"};
    printf("%s", seq[!!status]);
}

void press_any(){
    bold(1); italic(1); 
    printf("\npressione qualquer tecla para continuar...");
    bold(0); italic(0); 
    getch();
}

void start(){
    printf("--explorer--\n");
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
    printf("    <r> renomear\n");
    rand_sleep(50, 100);
    printf("    <d> excluir\n");
    rand_sleep(50, 100);
    printf("    <h> mudar horario do sistema\n");
    rand_sleep(50, 100);
    printf("    <F1> ajuda\n");
    rand_sleep(1000, 2500);
    press_any();
}

int main() {
    srand(time(NULL));

    start();


    return 0;
}
