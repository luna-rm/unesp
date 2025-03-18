#include<bits/stdc++.h> 

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--){   
        int total = 0;   
        int m, a, b, c;
        cin >> m >> a >> b >> c;

        int m1 = m, m2 = m;
    
        if(m1 < a){
            total += m1;
            m1 = 0;
        } else {
            total += a;
            m1 = m-a;
        }

        if(m2 < b){
            total += m2;
            m2 = 0;
        } else {
            total += b;
            m2 = m2-b;
        }

        if(m1+m2 >= 0){
            if(m1+m2 < c){
                total += m1+m2;
            } else {
                total += c;
            }
        }

        cout << total << endl;
    }

    return 0;
}