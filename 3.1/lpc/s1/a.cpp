#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    priority_queue<int> p;
    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        p.push(aux);
    }

    vector<int> v;
    for(int i = 0; i < n; i++){
        v.push_back(p.top());
        p.pop();
    }

    int r = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(v[i] - v[j] > k){
                break;
            }
            if(v[i] - v[j] == k){
                r++;
            }
        }
    }

    cout << r << endl;

    return 0;
}