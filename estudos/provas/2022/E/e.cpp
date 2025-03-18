#include<bits/stdc++.h> 

using namespace std;

int main() {
    //ler variaveis
    int n, k, e;
    cin >> n >> k >> e;
    
    //descobrir valor a direita da peça
    int d = n - k - e;

    //vetor de peças já usadas
    vector<int> pieces;
    pieces.push_back(k);

    //começando do tamanho max da direita, passar até chegar ao tamanho 0
    for(int i = d; i > 0; i--){
        //verificar se a peça já foi usada
        int aux = 0;
        for(int a : pieces){
            if(a == i){
                aux = 1;
                break;
            }
        }
        if(aux){
            continue;
        }

        //se a peça não for usada, verificar se ela é menor que d, se sim, adicionar as peças usadas
        //diminuir d, e diminuir o tamanhi i para d
        if(i <= d){
            pieces.push_back(i);
            d -= i;
            i = d;
        }        
    }

    //repetir os mesmos passos substituindo d por e
    for(int i = e; i > 0; i--){
        int aux = 0;
        for(int a : pieces){
            if(a == i){
                aux = 1;
                break;
            }
        }
        if(aux){
            continue;
        }
        if(i <= e){
            pieces.push_back(i);
            e -= i;
            i = e;
        }        
    }

    //printar a soma de d e e
    cout << d + e << endl;

    return 0;
}