#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct no {
    struct no * prox;
    int value;
} no;

typedef struct desc {
    no * first;
    int hm;
    no * end;
} desc;

void init_list(desc * info) {
    info->end = NULL;
    info->first = NULL;
    info->hm = 0;
}

void add(desc * info, int value){
    no * p = (no *) malloc(sizeof(no));
    p->value = value;

    info->hm++;

    if(info->hm == 1){
        p->prox = p;
        info->first = p;
        info->end = p;
        return;
    }

    no * aux = info->first;

    int how_many = info->hm;
    int done = 0;
    while(how_many--){
        if(p->value < aux->prox->value){
            done = 1;
            p->prox = aux->prox;
            aux->prox = p;
            break;
        }
        aux = aux->prox;
    }

    if(!done){
        p->prox = aux->prox;
        aux->prox = p;
        info->end = p;
    }
}

void pritn(desc * info){
    no * p = info->first;
    int how_many = info->hm;
    
    while(how_many--){
        printf("%d\n", p->value);
        p = p->prox;
    }
}


void remov(desc * info, int value){
    no * p = info->first;
    int how_many = info->hm;
    info->hm--;
    
    while(how_many--){
        if(p->prox->value == value){
            no * q = p->prox;
            if(q == info->end){
                info->end = p;
            } else if(q == info->first){
                info->first = q->prox;
            }
            p->prox = p->prox->prox;
            free(q); 
        }
        p = p->prox;
    }
}

int main() {
    desc info;

    init_list(&info);

    add(&info, 1);

    pritn(&info);
    printf("\n");

    add(&info, 2);

    pritn(&info);
    printf("\n");

    add(&info, 4);

    pritn(&info);
    printf("\n");

    add(&info, 3);

    pritn(&info);
    printf("\n");
    
    remov(&info, 3);

    pritn(&info);
    printf("\n");
    
    return 0;
}
