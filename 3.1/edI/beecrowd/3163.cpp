#include<bits/stdc++.h> 

using namespace std;

int main() {
    string aux;
    cin >> aux;

    int dir = 0;
    vector<string> N;
    vector<string> W;
    vector<string> S;
    vector<string> E;
    while(aux != "0"){
        if(aux[0] == '-'){
            dir = aux[1];
        } else {
            if(dir == '1'){
                N.push_back(aux);
            } else if (dir == '2'){
                S.push_back(aux);
            } else if(dir == '3'){
                W.push_back(aux);
            } else {
                E.push_back(aux);
            }
        }
        cin >> aux;
    }

    int s = max(W.size(), max(E.size(), max(S.size(), N.size())));

    for(int i = 0; i < s; i++){
        if(N.size() > i){
            cout << N[i] << " ";
        }
        if(W.size() > i){
            cout << W[i] << " ";
        }
        if(S.size() > i){
            cout << S[i] << " ";
        }
        if(E.size() > i){
            cout << E[i] << " ";
        }
    }

    cout << endl;

    return 0;
}