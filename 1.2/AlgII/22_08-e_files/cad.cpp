#include<bits/stdc++.h> 

using namespace std;

struct student {
    int ra;
    string name;
    double p1, p2, mt, freq;
};


int main() {

    FILE * arq = fopen("alunos.dat", "a+b");

    if(!arq){
        exit(0);
    }

    while(1){
        system("cls");

        student aux;

        cout << "--'0' para parar!--" << endl << endl;

        cout << "ra: ";
        cin >> aux.ra;

        if(!aux.ra){
            break;
        }

        cout << endl << "name: ";
        cin >> aux.name;

        cout << endl << "p1: ";
        cin >> aux.p1;

        cout << endl << "p2: ";
        cin >> aux.p2;

        cout << endl << "mt: ";
        cin >> aux.mt;

        cout << endl << "freq: ";
        cin >> aux.freq;

        fwrite(&aux, sizeof(student), 1, arq);
    }

    fflush(stdin);
    fclose(arq);

    return 0;
}

