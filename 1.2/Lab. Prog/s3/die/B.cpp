#include<bits/stdc++.h> 

using namespace std;


int main() {

    int cases;
    cin >> cases;

    for(int c = 1; c < cases+1; c++){
        int op, ansr = 0;
        cin >> op;
        cin.ignore();
        vector<int> v;
        for(int o = 0; o < op; o++){
            string a;
            getline(cin, a);

            if(a == "LEFT"){
                v.push_back(-1);
                ansr -= 1;
            } else if(a == "RIGHT"){
                v.push_back(1);
                ansr += 1;
            } else {
                int aux = a.back() - '0';
                v.push_back(v[aux-1]);
                ansr += v[aux-1];
            }
            //fflush(stdin);
        }
        cout << ansr << endl;
    }

    return 0;
}