#include<bits/stdc++.h> 

using namespace std;

int main() {
    int t;
    cin >> t;

    for(int x = 0; x < t; x++){
        int n;
        cin >> n;
        vector<int> v;

        while (n--){
            int aux;
            cin >> aux;
            v.push_back(aux);
        }

        int m = -1;
        for(unsigned int i = 0; i < v.size(); i++){
            if(m < v[i]){
                m = v[i];
            }
        } 

        cout << "Case " << x+1 << ": " << m << endl; 
    }
    

    return 0;
}