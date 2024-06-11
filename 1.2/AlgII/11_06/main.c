#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct prod no;
struct prod {
    int id;
    no* prox;
};

void cria_lista(no** lista){
    *lista = NULL;
}

void insert_ele(no** lista, int value){
    no * p = (no *)malloc(sizeof(struct prod);
    p->id = value;
    p->prox = NULL;

    if(*lista = NULL){
        *lista = p;
        return;
    }

    no * aux = *lista;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = p;
}

int main() {
    no* lista;
    cria_lista(lista);
    int value = -1;
    printf()
    while()



    return 0;
}
