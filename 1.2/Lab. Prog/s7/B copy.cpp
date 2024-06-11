#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    char mat[1000][1000];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }

    char end[1000][1000];
    for(int i = 0; i < n*n; i++){
        for(int j = 0; j < n*n; j++){
            end[i][j] = mat[i][j];
        }
    }
    for(int i = 0; i < n*n; i++){
        for(int j = 0; j < n*n; j++){
            mat[i][j] = '.';
        }
    }

    for(int k_aux = 2; k_aux <= k; k_aux++){
        for(int i = 0; i < pow(n, k_aux-1); i++){
            for(int j = 0; j < pow(n, k_aux-1); j++){
                if(end[i][j] == '*'){
                    for(int i2 = i*pow(n, k_aux-1); i2 < (i+1)*pow(n, k_aux-1); i2++){
                        for(int j2 = j*pow(n, k_aux-1); j2 < (j+1)*pow(n, k_aux-1); j2++){
                            mat[i2][j2] = '*';
                        }
                    }
                }
            }            
        }
        for(int i = 0; i < pow(n, k_aux); i++){
            for(int j = 0; j < pow(n, k_aux); j++){
                end[i][j] = mat[i][j];
                mat[i][j] = '.';
                cout << end[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    
    return 0;
}