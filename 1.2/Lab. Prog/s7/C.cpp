#include<bits/stdc++.h> 

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int mat[m+1][n+1];
    vector<int> vec;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> mat[i][j];
        }
    }
/* 
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(vec)
            cin >> mat[i][j];
        }
    } */



    return 0;
}