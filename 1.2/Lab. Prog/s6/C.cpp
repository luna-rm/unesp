#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;

    string number;
    //vector<string> v;

    cin >> number;

    int z = 0;
    for(int i = 0; i < n; i++){
        if(number[i] == 'n'){
            cout << "1 ";
        }
        if(number[i] == 'z'){
            z++;
        }
    }
    while(z--){
        printf("0 ");
    }

    return 0;
}