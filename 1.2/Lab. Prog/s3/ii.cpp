#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n, c, s, now = 1, ansr = 0;
    cin >> n >> c >> s;

    if(s == now){
        ansr++;
    }

    while(c--){
        int aux;
        cin >> aux;

        if(aux == 1){
            now++;
        } else {
            now--;
        }

        if(now > n){
            now = 1;
        } else if(now == 0){
            now = n;
        }

        if(now == s){
            ansr++;
        }
    }

    cout << ansr << endl;

    return 0;
}