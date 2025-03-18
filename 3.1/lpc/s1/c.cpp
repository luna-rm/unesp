#include<bits/stdc++.h> 

using namespace std;

int main() {
    string a;
    cin >> a;

    char m = '.';
    int n = 1, b = 1;
    for(unsigned int i = 0; i < a.size(); i++){
        if(m == a[i]){
            n++;
        } else {
            m = a[i];
            if(n > b){
                b = n;
            }
            n = 1;
        }        
    }
    if(n > b){
        b = n;
    }

    cout << b << endl;

    return 0;
}