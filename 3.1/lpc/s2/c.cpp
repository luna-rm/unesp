#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    vector<int> v;
    int side = 0;
    while(n--){
        string s;
        cin >> s;
        
        if(s == "back"){
            if(v.size()){
                if(!side){
                    cout << v[v.back()] << endl;
                    v.erase(v.end());
                } else {
                    cout << v[0] << endl;
                    v.erase(v.begin());
                }
            } else {
                cout << "No job for Ada?" << endl;
            }
        } else if(s == "front"){
            if(v.size()){
                if(!side){
                    cout << v[0] << endl;
                    v.erase(v.begin());
                } else {
                    cout << v[v.back()] << endl;
                    v.erase(v.end());
                }
            } else {
                cout << "No job for Ada?" << endl;
            }
        } else if(s == "reverse"){
            side = !side;
        } else if(s == "push_back"){
            int aux;
            cin >> aux;
            if(!side){
                v.push_back(aux);
            } else {
                v.insert(v.begin(), aux);
            }
        } else if(s == "toFront"){
            int aux;
            cin >> aux;
            if(!side){
                v.insert(v.begin(), aux);
            } else {
                v.push_back(aux);
            }
        }  

        /* for(auto a: v){
            cout << a << " ";
        }
        cout << endl; */
    }

    return 0;
}