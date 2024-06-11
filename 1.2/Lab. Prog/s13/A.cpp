#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    while(n--){
        string a;
        cin >> a;
        if(a.size() == 2){
            cout << a[1] << endl;
        } else {
            sort(a.begin(), a.end());
            cout << a[0] << endl;
        }
    }

    return 0;
}