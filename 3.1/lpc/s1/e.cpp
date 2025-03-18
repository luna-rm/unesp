#include<bits/stdc++.h> 

using namespace std;

int main() {
    char base[4];
    base[0] = 'v';
    base[1] = '<';
    base[2] = '^';
    base[3] = '>';

    char init, end;
    cin >> init >> end;

    int n;
    cin >> n;

    int aux_i, aux_e;
    for(int i = 0; i < 4; i++){
        if(base[i] == init){
            aux_i = i+1;
        }
        if(base[i] == end){
            aux_e = i+1;
        }
    }

    n = n % 4;

    int icw = aux_i;
    int iccw = aux_i;

    cout << "i: " << aux_i << endl;
    cout << "e: " << aux_e << endl;

    icw += n;
    while(icw >= 4){
        icw = icw - 4;
    }

    cout << "icw: " << icw << endl;

    if(icw == aux_e){
        cout << "cw" << endl;
        return 0;
    }

    iccw -= n;
    if(iccw <= 0){
        iccw = iccw + 4;
    }

    cout << "iccw: " << iccw << endl;

    if(iccw == aux_e){
        cout << "ccw" << endl;
        return 0;
    }

    cout << "undefined" << endl;

    return 0;
}