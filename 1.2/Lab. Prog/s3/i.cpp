#include<bits/stdc++.h> 

using namespace std;

int main() {
    char a;
    cin >> a;
    double t = 0;
    for(int i = 0; i < 12; i++){
        for(int j = 0; j < 12; j++){
            if(i>j){
                double aux;
                cin >> aux;
                t+=aux;
            }
        }
    }
    if(a == 'M'){
        t = t/66;
    }
    cout << fixed << setprecision(1) << t << endl;

    return 0;
}