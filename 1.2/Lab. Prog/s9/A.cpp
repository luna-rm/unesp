#include<bits/stdc++.h> 

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;

        int equal = 0;
        vector<int> vet;
        
        while(n--){
            int aux;
            cin >> aux;
            for(unsigned int i = 0; i < vet.size(); i++){
                if(aux == vet[i]){
                    equal = 1;
                }
            }
            if(!equal){
                vet.push_back(aux);
            }
        }

        if(equal){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}