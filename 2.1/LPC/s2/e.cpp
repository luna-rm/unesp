#include<bits/stdc++.h> 

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--){
        int s, p;
        priority_queue<int> lists;
        cin >> s >> p;

        while(s--){
            int aux;
            cin >> aux;
            lists.push(aux);
        }

        int ansr = 0, a = 1;
        while(p>0){
            if(lists.top() == 0){
                a = 0;
                break;
            }
            p = p - lists.top();
            lists.push(lists.top()/2);
            lists.pop();
            ansr++;
        }
        if(a){
            cout << ansr << endl;
        } else {
            cout << "Evacuate" << endl;
        }

    }
    return 0;
}