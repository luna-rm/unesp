#include<bits/stdc++.h> 

using namespace std;

int main() {
    int x, n, v;
    cin >> x >> n >> v;
    while(x != 0 || n != 0 || v != 0){
        int time = 0;
        if(x <= 30){
            time = 30;
        } else {
            time = 50;
        }

        map <string, vector <pair<int, string>>> grafo;

        while(n--){
            string a, b;
            int c;
            cin >> a >> b >> c;

            grafo[a].push_back({c, b});
        }

        priority_queue <pair<int, string>, vector <pair<int, string>>, greater <pair<int, string>>> prio;
        vector <pair<int, string>> visited;

        prio.push(make_pair(0, "varzea"));
        while(!prio.empty()){
            pair<int, string> act = prio.top();
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
            for(int i = 0; i < grafo[act.second].size(); i++){
                prio.push(make_pair(act.first+grafo[act.second][i].first, grafo[act.second][i].second));
            }
        }

        int hour = 17;
        for(auto c: visited){
            if(c.second == "alto"){
                time += c.first;
                break;
            }
        }

        hour += time/60;
        time = time%60;
        if(time<10){
            cout << hour << ":0" << time << endl;
        }else{
            cout << hour << ":" << time << endl;
        }

        if(hour>18 || (hour == 18 && time != 0)){
            cout << "Ira se atrasar" << endl;
        }else{
            cout << "Nao ira se atrasar" << endl;
        }
        cin >> x >> n >> v;
    }


    return 0;
}