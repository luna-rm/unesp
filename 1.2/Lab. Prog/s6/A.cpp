#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long double> vet;
    vet.push_back(2050);

    while(n--){
        long double aux;
        int ansr = 0;

        cin >> aux;

        while(vet.back() < aux){
            vet.push_back(vet.back()*10);
        }

        for(int i = vet.size()-1; i >= 0; i--){
            while(aux >= vet[i]){
                aux -= vet[i];
                ansr++;
            }
            if(aux == 0){
                break;
            }
        }

        if(ansr == 0 || aux != 0){
            cout << "-1" << endl;
            continue;
        }
        cout << (int) ansr << endl;
    }

    return 0;
}