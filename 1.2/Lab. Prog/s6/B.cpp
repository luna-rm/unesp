#include<bits/stdc++.h> 

using namespace std;

int main() {
    int m, n, field = 0;
    cin >> m >> n;
    
    while(1){
        field++;
        cout << "Field #" << field << ":" << endl;

        vector<vector<int>> mat;

        for(int i = 0; i < m; i++){
            vector<int> line;
            for(int j = 0; j < n; j++){
                char aux;
                cin >> aux;
                if(aux == '*'){
                    line.push_back(-1);
                    continue;
                }   
                line.push_back(0);
            }
            mat.push_back(line);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == -1){
                    int top = false, bottom = false;
                    if(i-1 >= 0){
                        if(mat[i-1][j] != -1){
                            mat[i-1][j]++;
                        }
                        bottom = true;
                    }
                    if(i+1 < m){
                        if(mat[i+1][j] != -1){
                            mat[i+1][j]++;
                        }
                        top = true;
                    }
                    if(j-1 >= 0){
                        if(mat[i][j-1] != -1){
                            mat[i][j-1]++;
                        }
                        if(bottom){
                            if(mat[i-1][j-1] != -1){
                                mat[i-1][j-1]++;
                            }
                        }
                        if(top){
                            if(mat[i+1][j-1] != -1){
                                mat[i+1][j-1]++;
                            }
                        }
                    }
                    if(j+1 < n){
                        if(mat[i][j+1] != -1){
                            mat[i][j+1]++;
                        }
                        if(bottom){
                            if(mat[i-1][j+1] != -1){
                                mat[i-1][j+1]++;
                            }
                        }
                        if(top){
                            if(mat[i+1][j+1] != -1){
                                mat[i+1][j+1]++;
                            }
                        }
                    }                    
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == -1){
                    cout << '*';
                    continue;
                }
                cout << mat[i][j];
            }
            cout << endl;
        }

        cin >> m >> n;
        if(m == 0 && n == 0){
            break;
        }
        cout << endl;
    }

    return 0;
}