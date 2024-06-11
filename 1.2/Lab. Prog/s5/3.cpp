#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[4] = {0, 0, 0, 0};
    while(n--){
        int aux;
        cin >> aux;
        if(aux%2 == 0){
            a[0]++;
        }
        if(aux%3 == 0){
            a[1]++;
        }
        if(aux%4 == 0){
            a[2]++;
        }
        if(aux%5 == 0){
            a[3]++;
        }
    }

    cout << a[0] << " Multiplo(s) de 2" << endl;
    cout << a[1] << " Multiplo(s) de 3" << endl;
    cout << a[2] << " Multiplo(s) de 4" << endl;
    cout << a[3] << " Multiplo(s) de 5" << endl;

    return 0;
}