#include<bits/stdc++.h> 

using namespace std;

int main() {
    //criação de variaveis
    int n, h, w;
    cin >> n >> h >> w;

    //repetir número de dias
    //caso chova ou esteja sem no trabalho, adicionar guarda-chuva no trabalho e tirar da casa e printar "Y"
    //caso chova ou esteja sem na casa, adicionar guarda-chuva na casa e tirar do trabalho e printar "Y"
    while(n--){
        string aux;
        cin >> aux;

        if(aux == "Y"){
            cout << "Y ";
            h--;
            w++;
        } else if(w == 0){
            cout << "Y ";
            h--;
            w++;
        } else {
            cout << "N ";
        }

        cin >> aux;

        if(aux == "Y"){
            cout << "Y";
            w--;
            h++;
        } else if(h == 0){
            cout << "Y";
            w--;
            h++;
        } else {
            cout << "N";
        }
        cout << endl;
    }

    return 0;
}