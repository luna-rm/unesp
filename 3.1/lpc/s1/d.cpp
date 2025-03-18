#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n; 
    cin >> n;

    if(n == 1){
        cout << n << endl;
    }

    if(n < 5) {
        cout << "NO SOLUTION" << endl;
        return 0;
    } 

    vector<int> v;
    for(int i = n; i > 0; i--){
        if(i % 2 == 0){
            v.insert(v.begin() + (int) (v.size()/2), i);
        } else {
            v.push_back(i);
        }
    }

    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}