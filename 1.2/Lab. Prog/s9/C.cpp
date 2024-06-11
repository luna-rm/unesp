#include<bits/stdc++.h> 

using namespace std;

bool how_to_sort(const pair<int,int> &a, const pair<int,int> &b){
    if(a.first < b.first){
        return true;
    } else if(a.first == b.first){
        return a.second > b.second;
    } else {
        return false;
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> init;

    while(n--){
        int aux;
        cin >> aux;
        init.push_back({aux, init.size()+1});
    }

    sort(init.begin(), init.end(), how_to_sort);

    for(unsigned int i = 0; i < init.size(); i++){
        cout << init[i].second << endl;
    }

    return 0;
}