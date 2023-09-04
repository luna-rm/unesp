#include<bits/stdc++.h> 

using namespace std;

int main() {
    int c;
    cin >> c;
    while (c--) {
        int j = 0, m = 0;
        for(int i = 0; i < 3; i++){
            int x, d;
            cin >> x >> d;
            j += x*d;
        }
        for(int i = 0; i < 3; i++){
            int x, d;
            cin >> x >> d;
            m += x*d;
        }
        if(j > m){
            cout << "JOAO" << endl;
        } else {
            cout << "MARIA" << endl;
        }
    }
    
    return 0;
}