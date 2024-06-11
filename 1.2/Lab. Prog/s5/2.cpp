#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--){
        int c, d;
        double ansr;
        cin >> c >> d;
        if(c == d && c == 0){
            cout << "0" << endl;
            continue;
        }

        ansr = pow(26, c) * pow(10, d);
        cout << (int)ansr << endl;
    }

    return 0;
}