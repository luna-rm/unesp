#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vet;

    while(n--){
        int aux;
        cin >> aux;
        vet.push_back(aux);
    }

    int ansr = 0;
    int bigger = 0;
    for(unsigned int i = 0; i < vet.size(); i++){
        int aux = vet[i];
        vet[i] -= bigger;
        ansr += abs(vet[i]);
        cout << ansr << endl;
        if(bigger < aux){
            bigger = aux;
        }
    }

    cout << ansr << endl;

    return 0;
}