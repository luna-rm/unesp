#include<bits/stdc++.h> 

using namespace std;

int main() {
    string s;
    cin >> s;

    int one = 0, two = 0, three = 0;
    for(unsigned int i = 0; i < s.size(); i+=2){
        if(s[i] == '1'){
            one++;
        } else if(s[i] == '2'){
            two++;
        } else if(s[i] == '3'){
            three++;
        }
    }

    int aux = 0;
    while(one--){
        if(aux){
            cout << "+";
        } else {
            aux++;
        }
        cout << "1";
    }

    while(two--){
        if(aux){
            cout << "+";
        } else {
            aux++;
        }
        cout << "2";
    }

    while(three--){
        if(aux){
            cout << "+";
        } else {
            aux++;
        }
        cout << "3";
    }

    cout << endl;

    return 0;
}