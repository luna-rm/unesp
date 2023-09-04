#include<bits/stdc++.h> 

using namespace std;


int main() {
    int hm;
    while(scanf("%d", &hm) != EOF){
        int before = 0, act = 0, diff = 0, size = 0;
        while(scanf("%d", &act) != EOF){
            if(diff == 0 && before == 0){
                before = act;
            } else{
                int aux = abs(act - before);
                
                if(diff < aux) {
                    diff = aux;
                }

                before = act;
            }
            size++;
        }
        if((diff < size) || diff == 0){
            cout << "Jolly";
        } else {
            cout << "Not jolly";
        }
        cout << endl;
    }

    return 0;
}