#include<bits/stdc++.h> 

using namespace std;

int main() {
    int y, b, r;
    cin >> y >> b >> r;

    if(r <= b && r <= y + 1){
        cout << (3 * r) - 3 << endl;
    } else if(b <= y){
        cout << (3 * b) << endl;
    } else {
        cout << (3 * y) + 3 << endl;
    }

    return 0;
}