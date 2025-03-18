#include<bits/stdc++.h> 
//priority queue with all smallest paths

using namespace std;

#define lli long long int

int main() {
    map <lli, vector<lli>> mapa;
    
    lli n;
    cin >> n;

    lli path[n];
    vector<lli> need;

    for(lli i = 0; i < n; i++){
        if((i+1) % 2 == 0){
            path[i] = i+1;
        } else {
            path[i] = 0;
            need.push_back(i+1);
        }

        lli aux;
        for(lli j = 0; j < n; j++){
            cin >> aux;
            mapa[i+1].push_back(aux);
        }
    }

    /* for(lli i = 0; i < n; i++){
        cout << path[i] << " ";
    }
    cout << endl;

    for(unsigned lli i = 0; i < need.size(); i++){
        cout << need[i];
    }
    cout << endl;
    cout << endl;

    for(lli i = 0; i < n; i++){
        for(lli j = 0; j < n; j++){
            cout << mapa[i+1][j] << " ";
        }
        cout << endl;
    } */

    lli perc = 0;
    for(lli i = 0; i < n; i++){
        if((i+1) % 2 == 1){
            /* cout << "p:" << perc << endl;
            cout << i+1 << endl; */
            if(i+1 == 1){
                vector<lli> street = mapa[2];
                lli smallest = 10000000000;
                int witch = 0;
                for(lli aux : need){
                    if(street[aux-1] < smallest){
                        smallest = street[aux-1];
                        witch = aux;
                    }
                }
                need.erase(remove(need.begin(), need.end(), witch), need.end());
                perc += smallest;
            } else if(i+1 == n){
                /* for(int m = 0; m < n; m++){
                    cout << mapa[i+1][m]<< " ";
                }
                cout << endl << need[0] << endl; */
                perc += mapa[i][need[0]-1];
            } else {
                vector<lli> streetA = mapa[i];
                vector<lli> streetB = mapa[i+2];
                int witch = 0;
                lli sum = 10000000000;
                for(lli aux : need){
                    if(streetA[aux-1] + streetB[aux-1] < sum){
                        sum = streetA[aux-1] + streetB[aux-1];
                        witch = aux;
                    }
                }
                need.erase(remove(need.begin(), need.end(), witch), need.end());
                perc += sum;
            }
        }
    }

    /* cout << endl;
    cout << endl;

    for(lli i = 0; i < n; i++){
        cout << path[i] << " ";
    }
    cout << endl;

    for(unsigned lli i = 0; i < need.size(); i++){
        cout << need[i];
    }
    cout << endl; */
    cout << perc << endl;

    return 0;
}