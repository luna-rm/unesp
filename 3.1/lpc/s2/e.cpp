#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v;

    while(n--){
        int aux;
        cin >> aux;
        v.push_back(aux);
    }

    vector<int> arrows;
    for(int i = 0; i < v.size(); i++){
        int ac = 0;
        for(int j = 0; j < arrows.size(); j++){
            if(arrows[j]-1 == v[i]){
                arrows[j]--;
                ac = 1;
                break;
            }
        }
        if(!ac){
            arrows.push_back(v[i]);
        }
    }

    cout << arrows.size() << endl;

    return 0;
}