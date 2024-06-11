#include<bits/stdc++.h> 

using namespace std;

int main() {
    while(1){
        int a, d;
        cin >> a >> d;

        if(a == 0 && d == 0){
            break;
        }

        vector<int> va;
        while(a--){
            int aux;
            cin >> aux;
            va.push_back(aux);
        }

        vector<int> vd;
        while(d--){
            int aux;
            cin >> aux;
            vd.push_back(aux);
        }

        sort(va.begin(), va.end());
        sort(vd.begin(), vd.end());
        reverse(vd.begin(), vd.end());

        int aux = vd.size()-2;
        if(aux < 0){
            return 0;
        }

        if(va[0] >= vd[aux]){
            cout << "N" << endl;
        } else {
            cout << "Y" << endl;
        }
    }

    return 0;
}