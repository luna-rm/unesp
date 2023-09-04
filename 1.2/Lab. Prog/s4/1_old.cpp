#include<bits/stdc++.h> 

using namespace std;

int main() {
    while(1){
        int how_many;
        cin >> how_many;
        if(!how_many){
            break;
        }

        int before, climmbing = -1, first, ansr = 0, aux;

        cin >> first;
        before = first;
        how_many--;

        while (how_many--) {
            int up = 1;
            cin >> aux;

            if(aux < before){
                up = 0;
                cout << "MENOR" << endl;
            }

            if(climmbing == -1){
                climmbing = up;
            } else {
                if(up){
                    if(!climmbing){
                        ansr++;
                        climmbing = 1;
                    }
                } else {
                    if(climmbing){
                        ansr++;
                        climmbing = 0;
                    }
                }
            }
            
            before = aux;

            cout << up << " " << climmbing << " " << ansr << endl;

        }

        if(aux > first){
            if(!climmbing){
                ansr++;
            }
        } else {
            if(climmbing){
                ansr++;
            }
        }

        cout << ansr << endl;       

    }

    return 0;
}