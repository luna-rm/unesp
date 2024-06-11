#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    while(cin >> n){
        while(n--){
            string aux;
            cin >> aux;
            reverse(aux.begin(), aux.end());
            int num = 0;
            for(int i = 0; i < aux.size(); i++){
                if(aux[i] == '1'){
                    num += (int)pow(2, i);
                }
            }
            char minha_letra_muito_legal_que_eu_li_em_binario_do_exercicio_e_agr_vou_printa_la = num;
            cout << minha_letra_muito_legal_que_eu_li_em_binario_do_exercicio_e_agr_vou_printa_la;
        }
        cout << endl;
    }

    return 0;
}