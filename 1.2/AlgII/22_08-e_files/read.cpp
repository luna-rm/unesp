#include<bits/stdc++.h> 

using namespace std;

struct student {
    int ra;
    string name;
    double p1, p2, mt, freq;
};

int main() {

    FILE * arq = fopen("alunos.dat", "rb");

    if(!arq){
        exit(1);
    }

    /* int what = -1;
    while(1){
        system("cls");
        cout << "o que?" << endl << endl;

        cout << "0 - todos" << endl;
        cout << "1 - aprovados" << endl;
        cout << "2 - freq" << endl;

        cin >> what;

        if(what == 0){
            all_student();
        }
    }  */

    cout << "alunos" << endl << endl;

    student aux;
    while(fread(&aux, sizeof(student), 1, arq)){
        cout << "ra: ";
        cout << aux.ra;

        cout << endl << "name: ";
        cout << aux.name;

        cout << endl << "p1: ";
        cout << aux.p1;

        cout << endl << "p2: ";
        cout << aux.p2;

        cout << endl << "mt: ";
        cout << aux.mt;

        cout << endl << "freq: ";
        cout << aux.freq;

        cout << endl << endl;
    }

    fclose(arq);    

    return 0;
}