#include<bits/stdc++.h> 

using namespace std;

int main() {
    vector<vector<vector<char>>> all_frac;
    int n, k;

    cin >> n >> k;

    vector<vector<char>> aux_frac; 
    for(int i = 0; i < n; i++){
        vector<char> aux;
        for(int j = 0; j < n; j++){
            char input;
            cin >> input;
            aux.push_back(input);
        }
        aux_frac.push_back(aux);
    }

    all_frac.push_back(aux_frac);

    for(int k_aux = 2; k_aux <= k; k_aux++){
        vector<vector<char>> frac;
        for(int i = 0; i < pow(n, k_aux); i++){
            vector<char> aux;
            for(int j = 0; j < pow(n, k_aux); j++){
                aux.push_back('.');
            }
            frac.push_back(aux);
        }

        for(int i = 0; i < pow(n, k_aux-1); i++){
            for(int j = 0; j < pow(n, k_aux-1); j++){
                if(all_frac[0][i][j] == '*'){
                    for(int i2 = i*pow(n, k_aux); i2 < (i+1)*pow(n, k_aux-1); i2++){
                        for(int j2 = j*pow(n, k_aux-1); j2 < (j+1)*pow(n, k_aux-1); j2++){
                            frac[i2][j2] = '*';
                        }
                    }
                    cout << endl;
                }
            }
        }

        all_frac.push_back(frac);

        for(int i = 0; i < pow(n, k_aux); i++){
            for(int j = 0; j < pow(n, k_aux); j++){
                cout << frac[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}