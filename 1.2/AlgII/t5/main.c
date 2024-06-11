#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

typedef struct no {
    int day;
    int month;
    int year;

    int hour;
    int min;

    char desc[80];

    struct no * before;
    struct no * after;
} no;

void end(){
    system("cls");
    printf("Feito por: \n");
    printf("- Camila C. Silva\n");
    printf("- Luna R. Marchi\n");

    exit(1);
}

int add_list(no ** list, int hm){
    no* p = (no*)malloc(sizeof(struct no));

    printf("Insira a data do compromisso:\n"); 
    printf("Dia: ");
    scanf("%d", &p->day);
    printf( "Mes: ");
    scanf("%d", &p->month);
    printf("Ano: "); 
    scanf("%d", &p->year);
    printf("\n");

    printf("Insira o horario do compromisso:\n");
    printf("Hora: ");
    scanf("%d", &p->hour);
    printf("Minuto: "); 
    scanf("%d", &p->min);
    printf("\n");

    fflush(stdin);
    printf("Insira uma breve descricao do compromisso:\n");
    gets(p->desc);
    fflush(stdin);


    if(*list == NULL){
        p->before = NULL;
        p->after = NULL;
        *list = p;

        return 1;
    }

    no* aux = *list;

    if(hm == 1){
        int order = 0;
        if(aux->year > p->year){
            order = 1;
        }
        else if(aux->year == p->year && aux->month > p->month){
            order = 1;
        }
        else if(aux->year == p->year && aux->month == p->month && aux->day > p->day){
            order = 1;
        }

        aux->after = p;
        aux->before = p;
            
        p->after = aux;
        p->before = aux;

        if(order){
            *list = p;
        } 
    
        return 2;
    }

    do {
        if(aux->year > p->year){
            break;
        }
        else if(aux->year == p->year && aux->month > p->month){
            break;
        }
        else if(aux->year == p->year && aux->month == p->month && aux->day > p->day){
            break;
        }
        aux = aux->after;
    } while(aux != *list);

    p->before = aux->before;
    p->after = aux;

    aux->before->after = p;
    aux->before = p;

    return hm+1;
}

int LimparData(no ** list, int hm){
    no* p = *list;
    int old_hm = hm;
    int dia, mes, ano; 

    printf("Digite a data que deseja limpar:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    printf( "Mes: ");
    scanf("%d", &mes);
    printf("Ano: "); 
    scanf("%d", &ano);
    printf("\n");

    while(old_hm--){
        if(p->day == dia && p->month == mes && p->year == ano){
            if(p == *list){
                *list = p->after;
            }
            p->before->after = p->after;
            p->after->before = p->before;
            no* aux = p->after;
            free(p);
            p = aux;
            hm--;
        } else {
            p = p->after;
        }
    }
    
    return hm;
}

int change_date(no ** list, int hm){
    no* p = *list;
    int old_hm = hm;
    int dia, mes, ano, hora, min, resp; 

    printf("Digite a data do compromisso que deseja alterar:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    printf( "Mes: ");
    scanf("%d", &mes);
    printf("Ano: "); 
    scanf("%d", &ano);
    printf("\n");
    
    printf("Digite o horario do compromisso:\n");
    printf("Hora: ");
    scanf("%d", &hora);
    printf( "Minuto: ");
    scanf("%d", &min);
    printf("\n");

    while(old_hm--){
        if(p->day == dia && p->month == mes && p->year == ano && p->hour == hora && p->min == min){
            system("cls");            
            printf("%d/%d/%d\n", p->day, p->month, p->year);
            printf("%d:%d\n", p->hour, p->min);
            puts(p->desc);
            printf("\n");

            printf("\nDigite 1 se deseja alterar esse Compromisso: ");
            scanf("%d", &resp);
            if(resp==1){
                fflush(stdin);
                gets(p->desc);
                fflush(stdin);
            }
        }
        system("cls");
        p=p->after;
    }
}

int remove_specific(no ** list, int hm){
    no* p = *list;
    int old_hm = hm;
    char word[80]; 

    fflush(stdin);
    printf("Procurar por:\n");
    gets(word);
    fflush(stdin);

    while(old_hm--){
        system("cls");
        if(strstr(p->desc, word)){
            int ansr;
            
            printf("%d/%d/%d\n", p->day, p->month, p->year);
            printf("%d:%d\n", p->hour, p->min);
            puts(p->desc);
            printf("--/--\n");
            printf("\n\n");

            printf("\nDigite 1 se deseja apagar esse Compromisso: ");
            scanf("%d", &ansr);
            if(ansr == 1){
                if(p == *list){
                    *list = p->after;
                }
                p->before->after = p->after;
                p->after->before = p->before;
                no* aux = p->after;
                free(p);
                p = aux;
                hm--;
            }
        } else {
            p = p->after;
        }
    }
    
    return hm;
}

void printf_list(no ** list, int hm){
    no* p = *list;
    int dia, mes, ano; 

    printf("Digite a data que deseja consultar:\n");
    printf("Dia: ");
    scanf("%d", &dia);
    printf("Mes: ");
    scanf("%d", &mes);
    printf("Ano: "); 
    scanf("%d", &ano);
    printf("\n");
    system("cls");

    while(hm--){
        if(p->day == dia && p->month == mes && p->year == ano){
            printf("%d/%d/%d\n", p->day, p->month, p->year);
            printf("%d:%d\n", p->hour, p->min);
            puts(p->desc);
            printf("--/--\n");
            printf("\n");
        }
        p = p->after;
    }
    printf("\nAperte qualquer tecla p/ continuar");
    getch();
}

void search_word(no ** list, int hm){
    no* p = *list;
    char word[80]; 

    fflush(stdin);
    printf("Procurar por:\n");
    gets(word);
    fflush(stdin);
    system("cls");

    while(hm--){
        if(strstr(p->desc, word)){
            printf("%d/%d/%d\n", p->day, p->month, p->year);
            printf("%d:%d\n", p->hour, p->min);
            puts(p->desc);
            printf("--/--\n");
            printf("\n");
        } 
        p = p->after;
        
    }
    printf("\nAperte qualquer tecla p/ continuar");
    fflush(stdin);
    getch();
    fflush(stdin);
}

void change_word(no ** list, int hm){
    no* p = *list;
    char word[80]; 

    fflush(stdin);
    printf("Procurar por:\n");
    gets(word);
    fflush(stdin);
    system("cls");

    while(hm--){
        if(strstr(p->desc, word)){
            system("cls");
            printf("%d/%d/%d\n", p->day, p->month, p->year);
            printf("%d:%d\n", p->hour, p->min);
            puts(p->desc);
            printf("\n");

            int ansr;
            printf("\nDigite 1 se deseja alterar esse Compromisso: ");
            scanf("%d", &ansr);
            if(ansr == 1){
                system("cls");
                printf("Insira a data do compromisso:\n"); 
                printf("Dia: ");
                scanf("%d", &p->day);
                printf( "Mes: ");
                scanf("%d", &p->month);
                printf("Ano: "); 
                scanf("%d", &p->year);
                printf("\n");

                printf("Insira o horario do compromisso:\n");
                printf("Hora: ");
                scanf("%d", &p->hour);
                printf("Minuto: "); 
                scanf("%d", &p->min);
                printf("\n");

            }
        } 
        p = p->after;
        
    }
}

void save_file(no ** list, int hm){
    FILE * arq = fopen("agenda.txt", "w+");
    if(!arq){
        printf("erro ao salvar");
        getch();
        return;
    }

    no* p = *list;

    while(hm--){    
        fprintf(arq, "%d %d %d %d %d", p->year, p->month, p->day, p->hour, p->min);
        fputs(p->desc, arq);
        putc('\n', arq);
        p = p->after;
    }

    fclose(arq);
}

int read_file(no ** list, int hm){
    FILE * arq = fopen("agenda.txt", "r+");
    if(!arq){
        printf("erro ao salvar");
        getch();
        return hm;
    }

    no help;
    while (fscanf (arq, "%d %d %d %d %d", &help.year, &help.month, &help.day, &help.hour, &help.min) != EOF){
        no* p = (no*)malloc(sizeof(struct no));

        p->year = help.year;
        p->month = help.month;
        p->day = help.day;
        p->hour = help.hour;
        p->min = help.min;
        
        fgets(p->desc, 80, arq);

        no* aux = *list;
        
        if(*list == NULL){
            p->before = NULL;
            p->after = NULL;
            *list = p;
        } else if(hm == 1){
            
            int order = 0;
            if(aux->year > p->year){
                order = 1;
            }
            else if(aux->year == p->year && aux->month > p->month){
                order = 1;
            }
            else if(aux->year == p->year && aux->month == p->month && aux->day > p->day){
                order = 1;
            }

            aux->after = p;
            aux->before = p;
                    
            p->after = aux;
            p->before = aux;

            if(order){
                *list = p;
            } 
        } else {
            do {
                if(aux->year > p->year){
                    break;
                }
                else if(aux->year == p->year && aux->month > p->month){
                    break;
                }
                else if(aux->year == p->year && aux->month == p->month && aux->day > p->day){
                    break;
                }
                aux = aux->after;
            } while(aux != *list);

            p->before = aux->before;
            p->after = aux;

            aux->before->after = p;
            aux->before = p;
        }
        
        hm++;
    }

    fclose(arq);
    return hm;
}

int main() {
    no * list = NULL; 
    int hm = 0;

    char name[30];
    for(unsigned int i = 0; i < sizeof(name) || name[i] == '\0'; i++){
        name[i] = NULL;
    }
    printf("Qual seu nome?\n");
    gets(name);

    while(1){
        system("cls");
        printf("--AGENDA DE ");
        for(unsigned int i = 0; i < sizeof(name) || name[i] == '\0'; i++){
            printf("%c", toupper(name[i]));
        }
        printf("--\n\n");

        Sleep(10);

        printf("1 - Inserir Compromisso\n");
        printf("2 - Limpar Data\n");
        printf("3 - Remover Compromisso\n");
        printf("4 - Mostrar por Data\n");
        printf("5 - Procurar Compromissos\n");
        printf("6 - Alterar p/ Palavra\n");
        printf("7 - Alterar p/ Data\n");
        printf("8 - Salvar Disco\n");
        printf("9 - Ler Disco\n");
        printf("0 - Sair\n\n");

        int what = -1;
        
        while(what < 0 || what > 9){
            printf("O que fazer?\n");
            scanf("%d",&what);
        }

        system("cls");

        if(what == 1){
            hm = add_list(&list, hm);
        } else if(what == 2){
            hm = LimparData(&list, hm);
        } else if(what == 3){
            hm = remove_specific(&list, hm);
        } else if(what == 4){
            printf_list(&list, hm);
        } else if(what == 5){
            search_word(&list, hm);
        } else if(what == 6){
            change_word(&list, hm);
        } else if(what == 7){
            change_date(&list, hm);
        } else if(what == 8){
            save_file(&list, hm);
        } else if(what == 9){
            hm = read_file(&list, hm);
        } else if(what == 0){
            end();
        } 
    }

    return 0;
}