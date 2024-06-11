#include<bits/stdc++.h> 

using namespace std;

int main() {
    int c;
    while(cin >> c){
        int b;
        cin >> b;

        int ansr = c;
        while(1){
            c -= b;
            c++;
            ansr++;
            if(c < b){
                break;
            }
        }
        
        cout << ansr << endl;
    }

    return 0;
}