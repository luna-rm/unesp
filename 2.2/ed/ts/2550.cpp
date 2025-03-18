#include<bits/stdc++.h> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, a, b, c;
    while(cin >> n >> m){
        unordered_map <int, vector <pair<int, int>>> grafo;
        while(m--){
            cin >> a >> b >> c;
            grafo[a].push_back(make_pair(c, b));
            grafo[b].push_back(make_pair(c, a));
        }

        vector <bool> visited(n, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> prio;
        prio.push({0, 1});
        int resp = 0;
        int cont_v = 0;
        visited[0] = 1;
        
        while(!prio.empty()){
            pair<int, int> p = prio.top();
            prio.pop();

            int wt = p.first;
            int u = p.second;

            if (visited[u] == true){
                continue;
            }

            resp += wt;
            visited[u] = true;
            cont_v += 1;

            for(auto v: grafo[u]){
                if(visited[v.second] == false){
                    prio.push({v.first, v.second});
                } 
            }
        }
        if (cont_v == n){
            cout << resp << endl;
        } else {
            cout << "impossivel" << endl;
        }
    }


    return 0;
}