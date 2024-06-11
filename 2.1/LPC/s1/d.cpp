#include<bits/stdc++.h> 

using namespace std;

int main() {
    int b, s;
    cin >> b >> s;

    vector<int> lista;
    while(b--){
        int aux;
        cin >> aux;
        lista.push_back(aux);
    }
    int maior = 1;
    for(unsigned int i = 0; i < lista.size(); i++){
        if(lista[i] > maior){
            if(s % lista[i] == 0){
                maior = lista[i];
            }
        }
    }
    int res = (int) (s/maior);

    cout << res << endl;

    return 0;
}
