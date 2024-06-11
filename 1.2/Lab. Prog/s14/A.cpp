#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vet;
    int aux;
    
    while(n--){
        cin >> aux;
        vet.push_back(aux);
    }

    int ansr = 0, aValue;
    for(unsigned int i = 0; i < vet.size(); i++){
        aValue = vet[i];
        ansr += abs(aValue);

        for(unsigned int j = i; j < vet.size(); j++){
            vet[j] -= aValue;
        }
    }

    cout << ansr << endl;

    return 0;
}