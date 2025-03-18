#include<bits/stdc++.h> 

using namespace std;

int main() {
    int cities[10000][10000];
    int c, v;
    cin >> c >> v;

    for(int i = 0; i < c; i++){
        for(int j = 0; j < c; j++){
            cities[i][j] = 0;
        }
    }

    for(int i = 0; i < v; i++){
        int c1, c2, g;
        cin >> c1 >> c2 >> g;
        cities[c1][c2] = g;
    }

    int dist [10000];
    for(int i = 0; i < c; i++){
        dist[i] = 1000000;
    }
    dist[0] = 0;

    vector<pair<int,int>> prio;
    prio.push_back(make_pair(1,0));



    return 0;
}