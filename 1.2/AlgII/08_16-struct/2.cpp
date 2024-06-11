#include<bits/stdc++.h> 

using namespace std;

struct data{
    int dia;
    int mes;
    int ano;
};


struct empregado{
    string RG;
    data nascimento;
    data dda;
    double salario;
};

int main() {
    vector<empregado> lista_empregados;

    int how_many;
    cin >> how_many;

    while(how_many > 0){
        empregado aux;
        string date;

        cout << endl << "--NEW--" << endl << endl;
        
        cout << "RG: ";
        cin >> aux.RG;
        
        cout << endl << "nasc: ";
        cin >> date;
        aux.nascimento.dia = date[0] + date[1];
        aux.nascimento.mes = date[2] + date[3];
        aux.nascimento.ano = date[4] + date[5];

        cout << endl << "dda: ";
        cin >> date;
        aux.dda.dia = date[0] + date[1];
        aux.dda.mes = date[2] + date[3];
        aux.dda.ano = date[4] + date[5];

        cout << endl << "salario: ";
        cin >> aux.salario;

        lista_empregados.push_back(aux);

        how_many--;
    }

    system("cls");

    for(unsigned int i = 0; i < lista_empregados.size(); i++){
        cout << "Emp. " << i << endl;
        cout << lista_empregados[i].RG << endl;
        cout << lista_empregados[i].nascimento.dia << "/" << lista_empregados[i].nascimento.mes << "/" << lista_empregados[i].nascimento.ano << "/" << endl;
        cout << lista_empregados[i].dda.dia << "/" << lista_empregados[i].dda.mes << "/" << lista_empregados[i].dda.ano << "/" << endl;
        cout << lista_empregados[i].salario << endl << endl;
    }

    return 0;
}