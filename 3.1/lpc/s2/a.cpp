#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> q;
    while(n--){
        int aux; 
        cin >> aux;
        q.push(aux);
    }

    int r = 0;
    int n1, n2;
    
    while(!q.empty()){
        n1 = q.top();
        q.pop();
        n2 = q.top();
        q.pop();

        r += n1 - n2;
    }
    
    cout << r << endl;

    return 0;
}