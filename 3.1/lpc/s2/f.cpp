#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> sub;
    priority_queue<int, vector<int>, greater<int>> dec;

    while(n--){
        int aux;
        int dir;
        cin >> aux >> dir;

        if(dir){
            dec.push(aux);
        } else {
            sub.push(aux);
        }
    }

    int time = 0;
    int aux_time = time + 0;
    while(!sub.empty() || !dec.empty()){
        cout << time << endl;
        if(sub.empty()){
            while(1){
                if(time > dec.top()){
                    aux_time = time + 10
                }
                aux_time = time + dec.top() + 10;
                dec.pop();
                if(dec.empty()){
                    break;
                }
                if(dec.top() > aux_time){
                    break;
                }
            }
        } else if(dec.empty()) {
            while(1){
                aux_time = time + sub.top() + 10;
                sub.pop();
                if(sub.empty()){
                    break;
                }
                if(sub.top() > aux_time){
                    break;
                }
            }
        } else{
            if(sub.top() < dec.top()){
                while(1){
                    aux_time = time + sub.top() + 10;
                    sub.pop();
                    if(sub.top() > aux_time){
                        break;
                    }
                }
            } else {
                while(1){
                    aux_time = time + dec.top() + 10;
                    dec.pop();
                    if(dec.empty()){
                        break;
                    }
                    if(dec.top() > aux_time){
                        break;
                    }
                }
            }
        }

        time = aux_time;
        
    }
    cout << time << endl;

    return 0;
}