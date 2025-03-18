#include<bits/stdc++.h> 

using namespace std;

int main() {
    vector<int> fila;
    fila.push_back(0);
    fila.push_back(1);
    fila.push_back(2);
    fila.push_back(3);
    fila.push_back(4);

    string nome[5]; 
    nome[0] = "Sheldon";
    nome[1] = "Leonard";
    nome[2] = "Penny";
    nome[3] = "Rajesh";
    nome[4] = "Howard";

    int n;
    cin >> n;

    while(n--){
        fila.push_back(fila[0]);
        fila.push_back(fila[0]);
        if(n > 0){
            fila.erase(fila.begin());
        }
    }
    cout << nome[fila[0]] << endl;


    return 0;
}