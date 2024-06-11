#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no{
    int value;
    struct no * prox;
} no;

void insere(no **lista, int info){
    no* p = malloc(sizeof(struct no));
    p->value = info;

    if(*lista == NULL){
        p->prox = p;
        *lista = p;
        return;
    }

    no* aux = *lista;
    while(aux->prox != *lista){
        aux = aux->prox;
    }

    aux->prox = p;
    p->prox = *lista;
    //sem se for no final
    //*lista = p; 
}

void excluir_number(no ** lista, int info){
    no * p = malloc(sizeof(struct no));
    
    if(*lista == NULL){
        return;
    }
    
    p = *lista;

    while(p->prox->value != info){
        p = p->prox;    
    }

    if(p->prox == *lista){
        *lista = p->prox->prox;
    }

    no * aux = p->prox;
    p->prox = p->prox->prox;
    free(aux);
}

void show(no *p){
    no * aux = p;
    do {
        printf("%d", p->value);
        p = p->prox;
    } while(p != aux);
}


int main() {
    no *lista = NULL;
    
    insere(&lista, 1);
    insere(&lista, 2);
    insere(&lista, 4);
    
    excluir_number(&lista, 1);

    show(lista);

    return 0;
}
