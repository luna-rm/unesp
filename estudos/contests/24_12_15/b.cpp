#include<bits/stdc++.h> 

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){
        string a;
        cin >> a;
        vector<char> b;
        for(unsigned int i = 0; i < a.size(); i++){
            if(a[i] == 'w'){
                b.insert(b.begin(), 'w');
            } else if(a[i] == 'p'){
                b.insert(b.begin(), 'q');
            } else {
                b.insert(b.begin(), 'p');
            }
            
        }
        for(char aux : b){
            cout << aux;
        }
        cout << endl;
    }

    return 0;
}