#include<bits/stdc++.h> 

using namespace std;

int main() {
    typedef pair<int, int> pi; 
    priority_queue<pi, vector<pi>, greater<pi>> cash;
    queue<int> client;
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        pair<int,int> p = {0, aux};
        cash.push(p);
    }

    for(int i = 0; i < m; i++){
        int aux;
        cin >> aux;
        client.push(aux);
    }
    
    while(!client.empty()){
        int c = client.front();
        client.pop();
        pair<int,int> cashier = cash.top();
        cash.pop();

        cashier.first += c*cashier.second;
        cout << cashier.first << " " << cashier.second << endl;
        
        cash.push(cashier);

    }
    for(int i = 0; i < n-1; i++){
        cash.pop();
    }
    cout << cash.top().first << endl;


    return 0;
}