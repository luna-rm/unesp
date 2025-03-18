#include<bits/stdc++.h> 

using namespace std;

vector<pair<int, int[2][2]>> people;

void func(int now, int max){    
    int w = 0;

    if(people[now].second[0][1]){
        w = 1;
    }
    
    if(people[now].second[1][1]){
        w = 2;
    }

    for(int i = w; i < 2; i++){
        if(people[people[now].second[i][0]].first){
            continue;
        }
        people[people[now].second[i][0]].first += -1;
        people[now].second[i][1] += 1;
        
        func(people[now].second[now][0], max--);
    }

}

int main() {
    
    int n;
    cin >> n;

    while(n--){
        pair<int, int[2][2]> aux;
        cin >> aux.second[0][0] >> aux.second[1][0];
        aux.first = 0;
        aux.second[0][0] += -1;
        aux.second[1][0] += -1;
        people.push_back(aux);
    }

    //func(0, people.size()*2);

    for(unsigned int now = 0; now < people.size(); now++){
        for(int i = 0; i < 2; i++){
            people[people[now].second[i][0]].first += -1;
            people[now].second[i][1] += 1;
        }
    }

    for(unsigned int i = 0; i < people.size(); i++){
        cout << people[i].first;
        cout << " | ";
        cout << people[i].second[0][1];
        cout << " ";
        cout << people[i].second[1][1];
        cout << endl;
    }

    return 0;
}
