#include<bits/stdc++.h> 
#include<conio.h>

using namespace std;

typedef struct {
    int id;
    int pri;
    char name[100];
} person;

int add(person list[1000], int pos){
    person p_aux;
    cout << endl << "id: ";
    cin >> p_aux.id;
    cout << endl << "prioridade (0 to 2): ";
    cin >> p_aux.pri;
    fflush(stdin);
    cout << endl << "nome: ";
    gets(p_aux.name);
    fflush(stdin);

    int aux[2] = {0, pos};
    for(int i = 0; i < pos; i++){
        if(p_aux.pri <= list[i].pri){
            aux[0] = 1;
            aux[1] = i;
            break;
        }
    }

    if(aux[0]){
        for(int i = pos; i >= aux[1]; i--){
            list[i].id = list[i-1].id;
            list[i].pri = list[i-1].pri;
            strcpy(list[i].name, list[i-1].name);
        }
    }

    list[aux[1]].id = p_aux.id;
    list[aux[1]].pri = p_aux.pri;
    strcpy(list[aux[1]].name, p_aux.name);

    pos++;
    return pos;
}

int main() {
    person list[1000];
    int pos = 0, what = 0;
    while(what != 2){
        cout << "0 - add" << endl << "1 - remove" << endl << "2 - end" << endl << endl;
        cout << "lista atual: " << endl;
        for(int i = 0; i < pos; i++){
            cout << "id: " << list[i].id << " | pri.: " << list[i].pri << " | nome: " << list[i].name << endl;
        }
        cout << endl << endl << "fazer: ";
        cin >> what;

        if(what == 0){
            pos = add(list, pos);
        } else if(what == 1){
            if(!pos){
                cout << "nn tem ninguem" << endl << endl;
                getch();
                system("cls");
                continue;
            }
            cout << "atendendo -> id: " << list[pos-1].id << " | pri.: " << list[pos-1].pri << " | nome: " << list[pos-1].name << endl;
            pos--;
            getch(); 
        } else if(what == 2){
            exit(1);
        }
        system("cls");
    }
    pos = add(list, pos);
    
    return 0;
}
