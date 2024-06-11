#include<bits/stdc++.h> 

using namespace std;

int main() {
    string a;
    while(cin >> a){
        int open = 0;
        int good = 1;
        for(unsigned int i = 0; i < a.size(); i++){
            if(a[i] == '('){
                open++;
            }
            if(a[i] == ')'){
                open--;
                if(open < 0){
                    good = 0;
                    cout << "incorrect" << endl;
                    break;
                }
            }
        }
        if(good){
            if(!open){
                cout << "correct" << endl;
            } else {
                cout << "incorrect" << endl;
            }
        }
    }

    return 0;
}