#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;

        string mp;
        cin >> mp;

        int yes = 1;

        for(int j = 0; j < t-1; j++){
            string aux;
            cin >> aux; 

            int no = 0;
            for(int k = 0; k < mp.size(); k++){
                if(aux[k] == mp[k]){
                    no++;
                }
            }
            if(no == mp.size()){
                cout << "NO" << endl;
                yes = 0;
            }
        }

        if (yes) {
            cout << "Yes" << endl;
        }
    }

    return 0;
}