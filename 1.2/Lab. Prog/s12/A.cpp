#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int time = 60*4 - k;
    int ansr = 0;

    for(int i = 1; i < n+1; i++){
        time = time - 5*i;
        if(time < 0){
            break;
        }
        ansr++;
    }

    cout << ansr;

    return 0;
}