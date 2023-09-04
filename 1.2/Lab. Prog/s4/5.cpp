#include<bits/stdc++.h> 

using namespace std;

int main() {
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        int t = a+b+c;
        if(t == 0){
            cout << "*" << endl;
        }
        if(t == 3){
            cout << "*" << endl;
        }
        if(t == 1){
            if(a == 1){
                cout << "A" << endl;
            } else if(b == 1){
                cout << "B" << endl;
            } else if(c == 1){
                cout << "C" << endl;
            }
        }
        if(t == 2){
            if(a == 0){
                cout << "A" << endl;
            } else if(b == 0){
                cout << "B" << endl;
            } else if(c == 0){
                cout << "C" << endl;
            }
        }
    }

    return 0;
}