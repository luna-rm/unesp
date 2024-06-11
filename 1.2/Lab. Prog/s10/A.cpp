#include<bits/stdc++.h> 

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        int k, n;
        vector<int> vet;

        cin >> n;
        cin >> k;

        while(n--){
            int aux;
            cin >> aux;
            vet.push_back(aux);
        }

        sort(vet.begin(), vet.end());

        if(k == 1){
            cout << "0" << endl;
            continue;
        }

        int less = -1;

        for(unsigned int i = 0; i < vet.size()-k+1; i++){
            int aux = vet[i+k-1] - vet[i]; 
            if(less == -1 || aux < less){
                less = aux;
            }
        }

        cout << less << endl;
    }

    return 0;
}