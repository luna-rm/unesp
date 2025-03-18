#include<bits/stdc++.h> 

using namespace std;

int main() {
    string s;
    int topo = -1;
    char pilha[1001];

    while(cin >> s){
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == '(' || s[i] == ')'){
                topo++;
                pilha[topo] = s[i];
            }
        }
        topo++;
        int left = 0, right = 0, cor = 0;
        while(topo--){
            if(pilha[topo] == '('){
                left++;
            } else {
                right++;
            }
            if(right > left) {
                cor = 1;
            }
        }   
        if(cor || right != left){
            cout << "incorrect" << endl;
        } else {
            cout << "correct" << endl;
        }
    }

   
    return 0;
}