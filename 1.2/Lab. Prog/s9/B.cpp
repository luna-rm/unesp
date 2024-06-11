#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;

    
    vector<pair<int, int>> vet;
        
    while(n--){
        int aux;
        cin >> aux;
        int equal = 0;
        for(unsigned int i = 0; i < vet.size(); i++){
            if(aux == vet[i].first){
                equal = 1;
                vet[i].second++;
            }
        }
        if(!equal){
            vet.push_back({aux, 1});
        }
    }

    int big = -1;
    for(unsigned int i = 0; i < vet.size(); i++){
        if(big < vet[i].second){
            big = vet[i].second;
        }
    }  

    cout << big << " " << vet.size() << endl;

    return 0;
}