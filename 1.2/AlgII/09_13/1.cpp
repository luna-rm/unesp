#include<bits/stdc++.h> 

using namespace std;

int det(vector<vector<int>> mat){
    if(mat.size() == 1){
        cout << mat[0][0] << endl;
        return mat[0][0];
    }

    int ansr;
    for(unsigned int i = 0; i < mat.size(); i++){
        if(mat[0][i] == 0){
            continue;
        }
        vector<vector<int>> new_mat; 
        for(unsigned int j = 0; j < mat.size(); j++){
            if(j == i){
                continue;
            }
            vector<int> line;
            for(unsigned int k = 0; k < mat[i].size(); k++){
                if(k == i){
                    continue;
                }
                cout << mat[j][k] << " ";
                line.push_back(mat[j][k]);
            }
            cout << endl;
            new_mat.push_back(line);
        }    
        ansr += mat[0][i] * (int) pow(-1, i) * det(new_mat);
    }
    cout << ansr << endl;
    return ansr;
}

int main() {

    cout << endl << endl << det(vector<vector<int>> {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    return 0;
}