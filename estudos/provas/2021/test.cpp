#include<bits/stdc++.h> 

using namespace std;

int main() {
    //p1+p2
    int p1[2];
    int p2[2];

    cin >> p1[0] >> p1[1];
    cin >> p2[0] >> p2[1];

    //p3+p4
    int p3[2];
    int p4[2];

    cin >> p3[0] >> p3[1];
    cin >> p4[0] >> p4[1];

    int t;
    int u;
    int aux_t[2], aux_u[2];

    aux_t[0] = (p1[0]-p3[0])*(p3[1]-p4[1]) - (p1[1]-p3[1])*(p3[0]-p4[0]);
    aux_t[1] = (p1[0]-p2[0])*(p3[1]-p4[1]) - (p1[1]-p2[1])*(p3[0]-p4[0]);

    t = aux_t[0]/aux_t[1];

    aux_u[0] = (p1[0]-p2[0])*(p1[1]-p3[1]) - (p1[1]-p2[1])*(p1[0]-p3[0]);
    aux_u[1] = (p1[0]-p2[0])*(p3[1]-p4[1]) - (p1[1]-p2[1])*(p3[0]-p4[0]);

    u = aux_u[0]/aux_u[1];

    int aux = 1;
    if(t >= 0 && t <= 1){
        if(u >= 0 && u <= 1){
            aux = 0;
            cout << "int" << endl;
        }
    }
    if(aux){
        cout << "sem int" << endl;
    }

    return 0;
}