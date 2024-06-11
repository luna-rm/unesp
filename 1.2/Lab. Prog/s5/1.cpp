#include<bits/stdc++.h> 

using namespace std;

int main() {
    double n1, n2;
    cin >> n1 >> n2;

    if(n1 > 0){
        if(n2 > 0){
            cout << "Q1";
        } else {
            cout << "Q4";
        }
    } else if(n1 < 0) {
        if(n2 > 0){
            cout << "Q2";
        } else {
            cout << "Q3";
        }
    } else {
        if(n1 != 0){
            cout << "Eixo Y";
        } else if(n2 != 0){
            cout << "Eixo X";
        } else {
            cout << "Origem";
        }
    }

    cout << endl;

    return 0;
}