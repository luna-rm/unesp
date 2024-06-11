#include<bits/stdc++.h> 
#include<conio.h>

using namespace std;

typedef struct {
    int day;
    int month;
    int year;
} date;

typedef struct {
    int rg;
    char name[100];
    char prof[100];
    date birth;
} person;

void add(){
    person p_list[1000];
    int pos = 0;

    FILE * arq = fopen("people.txt", "r+");

    if(!arq){
        exit(1);
    }

    while(fscanf(arq, "%d %s %s %d %d %d", &p_list[pos].rg, p_list[pos].name, p_list[pos].prof, &p_list[pos].birth.day, &p_list[pos].birth.month, &p_list[pos].birth.year) != EOF){
        //cout << p_list[pos].rg << endl;
        pos++;
    }

    fclose(arq);

    person p_aux;
    cout << "rg: ";
    cin >> p_aux.rg;
    fflush(stdin);
    cout << endl << "nome: ";
    gets(p_aux.name);
    fflush(stdin);
    cout << endl << "profissao: ";
    gets(p_aux.prof);
    fflush(stdin);
    cout << endl << "nascimento (dd/mm/aaaa): ";
    scanf("%d/%d/%d", &p_aux.birth.day, &p_aux.birth.month, &p_aux.birth.year);

    int aux[2] = {0, pos};
    for(int i = 0; i < pos; i++){
        if(p_aux.rg < p_list[i].rg){
            aux[0] = 1;
            aux[1] = i;
            break;
        }
    }

    if(aux[0]){
        for(int i = pos; i >= aux[1]; i--){
            p_list[i].rg = p_list[i-1].rg;
            p_list[i].birth.day = p_list[i-1].birth.day;
            p_list[i].birth.month = p_list[i-1].birth.month;
            p_list[i].birth.year = p_list[i-1].birth.year;
            strcpy(p_list[i].name, p_list[i-1].name);
            strcpy(p_list[i].prof, p_list[i-1].prof);
        }
    }

    p_list[aux[1]].rg = p_aux.rg;
    p_list[aux[1]].birth.day = p_aux.birth.day;
    p_list[aux[1]].birth.month = p_aux.birth.month;
    p_list[aux[1]].birth.year = p_aux.birth.year;
    strcpy(p_list[aux[1]].name, p_aux.name);
    strcpy(p_list[aux[1]].prof, p_aux.prof);

    FILE * new_arq = fopen("people.txt", "w+");

    if(!new_arq){
        exit(1);
    }

    pos++;

    for(int i = 0; i < pos; i++){
        fprintf(new_arq, "%d %s %s %d %d %d ", p_list[i].rg, p_list[i].name, p_list[i].prof, p_list[i].birth.day, p_list[i].birth.month, p_list[i].birth.year);
    }

    fclose(new_arq);

    return;
}

void remove(){
    person p_list[1000];
    int pos = 0;

    FILE * arq = fopen("people.txt", "r+");

    if(!arq){
        exit(1);
    }

    while(fscanf(arq, "%d %s %s %d %d %d", &p_list[pos].rg, p_list[pos].name, p_list[pos].prof, &p_list[pos].birth.day, &p_list[pos].birth.month, &p_list[pos].birth.year) != EOF){
        pos++;
    }

    fclose(arq);

    int rg_aux;
    cout << "rg que sera retirado: ";
    cin >> rg_aux;

    FILE * new_arq = fopen("people.txt", "w+");

    if(!new_arq){
        exit(1);
    }

    int there_is = 0;
    for(int i = 0; i < pos; i++){
        if(rg_aux == p_list[i].rg){
            there_is++;
            continue;
        }
        fprintf(new_arq, "%d %s %s %d %d %d ", p_list[i].rg, p_list[i].name, p_list[i].prof, p_list[i].birth.day, p_list[i].birth.month, p_list[i].birth.year);
    }
    if(there_is){
        cout << endl << "pessoa retirada com sucesso" << endl << endl;
        getch();
    } else {
        cout << endl << "nn foi possivel retirar tal pessoa" << endl << endl;
        getch();
    }

    fclose(new_arq);

    return;
}

void show_all(){
    person p_aux;

    FILE * arq = fopen("people.txt", "r+");

    if(!arq){
        exit(1);
    }

    while(fscanf(arq, "%d %s %s %d %d %d", &p_aux.rg, p_aux.name, p_aux.prof, &p_aux.birth.day, &p_aux.birth.month, &p_aux.birth.year) != EOF){
        cout << "rg: " << p_aux.rg;
        cout << endl << "nome: " << p_aux.name;
        cout << endl << "profissao: " << p_aux.prof;
        cout << endl << "nascimento: " << p_aux.birth.day << "/" << p_aux.birth.month << "/" << p_aux.birth.year;
        cout << endl << endl << "---x---" << endl << endl;
    }

    getch();

    fclose(arq);
}

void count(){
    person p_aux;
    int res = 0;

    FILE * arq = fopen("people.txt", "r+");

    if(!arq){
        exit(1);
    }

    while(fscanf(arq, "%d %s %s %d %d %d", &p_aux.rg, p_aux.name, p_aux.prof, &p_aux.birth.day, &p_aux.birth.month, &p_aux.birth.year) != EOF){
        res++;
    }

    cout << "tem " << res << " pessoas";

    getch();

    fclose(arq);
}

void search(){
    int rg_aux;
    cout << "rg da pessoa: ";
    cin >> rg_aux;

    person p_aux;

    FILE * arq = fopen("people.txt", "r+");

    if(!arq){
        exit(1);
    }

    int found = 0;
    while(fscanf(arq, "%d %s %s %d %d %d", &p_aux.rg, p_aux.name, p_aux.prof, &p_aux.birth.day, &p_aux.birth.month, &p_aux.birth.year) != EOF){
        if(rg_aux != p_aux.rg){
            continue;
        }

        found++;
        cout << "--x--";
        cout << endl << "nome: " << p_aux.name;
        cout << endl << "profissao: " << p_aux.prof;
        cout << endl << "nascimento: " << p_aux.birth.day << "/" << p_aux.birth.month << "/" << p_aux.birth.year;
    }

    if(!found){
        cout << endl << "pessoa nao encontrada" << endl << endl;
    }

    getch();

    fclose(arq);
}

void show_30(){
    person p_aux;

    FILE * arq = fopen("people.txt", "r+");

    if(!arq){
        exit(1);
    }

    while(fscanf(arq, "%d %s %s %d %d %d", &p_aux.rg, p_aux.name, p_aux.prof, &p_aux.birth.day, &p_aux.birth.month, &p_aux.birth.year) != EOF){
        if(2023 - p_aux.birth.year < 30){
            continue;
        }
        cout << "rg: " << p_aux.rg;
        cout << endl << "nome: " << p_aux.name;
        cout << endl << "profissao: " << p_aux.prof;
        cout << endl << "nascimento: " << p_aux.birth.day << "/" << p_aux.birth.month << "/" << p_aux.birth.year;
        cout << endl << endl << "---x---" << endl << endl;
    }

    getch();

    fclose(arq);
}

void count_prof(){
    person p_aux;
    char prof_list[100][100];
    int how_many = 0;

    FILE * arq = fopen("people.txt", "r+");

    if(!arq){
        exit(1);
    }

    while(fscanf(arq, "%d %s %s %d %d %d", &p_aux.rg, p_aux.name, p_aux.prof, &p_aux.birth.day, &p_aux.birth.month, &p_aux.birth.year) != EOF){
        int found = 0;
        for(int i = 0; i < how_many; i++){
            if(!strcmp(p_aux.prof, prof_list[i])){
                found++;
                break;
            }
        }        
        if(!found){
            strcpy(prof_list[how_many], p_aux.prof);
            how_many++;
        }
    }

    cout << "tem " << how_many << " prof. diferentes" << endl << "sendo elas: " << endl;
    for(int i = 0; i < how_many; i++){
        cout << prof_list[i] << endl;
    }

    getch();

    fclose(arq);
}

void sort_name(){
    person p_list[1000];
    int pos = 0;

    FILE * arq = fopen("people.txt", "r+");

    if(!arq){
        exit(1);
    }

    person p_aux;
    while(fscanf(arq, "%d %s %s %d %d %d", &p_aux.rg, p_aux.name, p_aux.prof, &p_aux.birth.day, &p_aux.birth.month, &p_aux.birth.year) != EOF){
        int aux[2] = {0, pos};
        for(int i = 0; i < pos; i++){
            if(strcmp(p_aux.name, p_list[i].name) < 0){
                aux[0] = 1;
                aux[1] = i;
                break;
            }
        }

        if(aux[0]){
            for(int i = pos; i >= aux[1]; i--){
                p_list[i].rg = p_list[i-1].rg;
                p_list[i].birth.day = p_list[i-1].birth.day;
                p_list[i].birth.month = p_list[i-1].birth.month;
                p_list[i].birth.year = p_list[i-1].birth.year;
                strcpy(p_list[i].name, p_list[i-1].name);
                strcpy(p_list[i].prof, p_list[i-1].prof);
            }
        }

        p_list[aux[1]].rg = p_aux.rg;
        p_list[aux[1]].birth.day = p_aux.birth.day;
        p_list[aux[1]].birth.month = p_aux.birth.month;
        p_list[aux[1]].birth.year = p_aux.birth.year;
        strcpy(p_list[aux[1]].name, p_aux.name);
        strcpy(p_list[aux[1]].prof, p_aux.prof);
        
        pos++;
    }

    for(int i = 0; i < pos; i++){
        cout << "rg: " << p_list[i].rg;
        cout << endl << "nome: " << p_list[i].name;
        cout << endl << "profissao: " << p_list[i].prof;
        cout << endl << "nascimento: " << p_list[i].birth.day << "/" << p_list[i].birth.month << "/" << p_list[i].birth.year;
        cout << endl << endl << "---x---" << endl << endl;
    }

    getch();
    fclose(arq);
    return;
}

int main() { 
    FILE * arq = fopen("people.txt", "r+");
    if(!arq){
        fclose(arq);
        arq = fopen("people.txt", "w+");
        fclose(arq);
    }

    int what = -1;   
    while(what != 9){
        system("cls");
        cout << "0 - add" << endl;
        cout << "1 - remover" << endl;
        cout << "2 - mostrar todos" << endl;
        cout << "3 - contar" << endl;
        cout << "4 - procurar" << endl;
        cout << "5 - mostrar > 30 anos" << endl;
        cout << "6 - contar prof. dif." << endl;
        cout << "7 - ordenar p/ nome" << endl;
        cout << "8 - ordenar p/ rg" << endl;
        cout << "9 - end" << endl;

        cout << endl << "fazer: ";
        cin >> what;

        system("cls");

        if(what == 0){
            add();
        } else if(what == 1){
            remove();
        } else if(what == 2){
            show_all();
        } else if(what == 3){
            count();
        } else if(what == 4){
            search();
        } else if(what == 5){
            show_30();
        } else if(what == 6){
            count_prof();
        } else if(what == 7){
            sort_name();
        } else if(what == 8){
            show_all();
        } else if(what == 9){
            exit(1);
        }
    }
    
    return 0;
}
