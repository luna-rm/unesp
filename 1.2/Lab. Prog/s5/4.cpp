#include<bits/stdc++.h> 

using namespace std;

int main() {
    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        int count = 0;
        while(1){
            count += 1;
            int aux, ansr = 1;
            for(int i = 1; i < n+1; i++){
                cin >> aux;
                if(aux != i){
                    ansr = 0; 
                }
            }
            if(ansr){
                break;
            }
        }
        cout << count << endl;
    }

    return 0;
}