#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<pair<int,int>> v;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        v.push_back({aux, i});
    }

    int a = 0, b = 0;
    sort(v.begin(), v.end());

    int r = 0;
    for(int i = 0; i < v.size(); i++){
        a = v[i].first;
        b = s - a;

        if(a > b){
            for(int j = 0; j < v[i].second; j++){
                if(b == v[j].first){
                    cout << v[j].second+1 << " " << v[i].second+1 << endl;
                    r = 1;
                }
            }
        } else {
            for(int j = v[i].second+1; j < v.size()+1; j++){
                if(b == v[j].first){
                    cout << v[i].second+1 << " " << v[j].second+1 << endl;
                    r = 1;
                }
            }
        }
    }
    if(!r){
        cout << "IMPOSSIBLE";
    }

    return 0;
}