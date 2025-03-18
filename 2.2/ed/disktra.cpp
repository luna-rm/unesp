#include<bits/stdc++.h> 

using namespace std;

int main() {

    map <int, vector <pair<int, int>>> grafo;
    priority_queue <pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> prio;
    vector <pair<int,int>> visited;

    int nodes = 5;

    for(int i = 0; i < nodes; i++){
        while(1){
            cout << i+1 << endl;
            int to, value;
            cin >> to;
            if (!to){
                break;
            }
            cin >> value;
            grafo[i+1].push_back(make_pair(value, to));
        }
        cout << endl;
    }

    int sn = 0;
    cin >> sn;

    prio.push(make_pair(0, sn));
    while(!prio.empty()){
        cout << "-----" << endl;
        pair<int,int> act = prio.top();
        prio.pop();
        int done = 0;
        for(int i = 0; i < visited.size(); i++){
            if(act.second == visited[i].second){
                done = 1;
                break;
            }
        }
        if(done){
            continue;
        }
        visited.push_back(act);
        cout << "A" << endl;
        for(int i = 0; i < grafo[act.second].size(); i++){
            prio.push(make_pair(act.first+grafo[act.second][i].first, grafo[act.second][i].second));
            cout << act.first+grafo[act.second][i].first << " de " << grafo[act.second][i].second << endl;
        }
        for(int i = 0; i < visited.size(); i++){
            cout << visited[i].first << " " << visited[i].second << endl;
        }
        cout << "B ";
        cout << prio.top().second << endl;
        cout << endl;
    }

    return 0;
}