#include<bits/stdc++.h> 

using namespace std;

struct photo
{
    long long int a, b, u;
    long long int trash = 1;
};

int main() {
    long long int r, p, q;

    //criação de vetores
    vector<pair<long long int, long long int>> runners;
    vector<photo> photos;
    vector<pair<long long int, long long int>> queues;

    //leitura de variaveis
    cin >> r;
    while(r--){
        long long int t, s;
        cin >> t >> s;
        runners.push_back({t, s});
    }

    cin >> p;
    while(p--){
        photo aux;
        cin >> aux.u >> aux.a >> aux.b;
        aux.trash = 1;
        photos.push_back(aux);
    }

    cin >> q;
    while(q--){
        long long int t, s;
        cin >> t >> s;
        queues.push_back({t, s});
    }

    //passar por cada foto verificando se tem ao menos um corredor nela 
    for(unsigned long long int i = 0; i < photos.size(); i++){
        for(unsigned long long int j = 0; j < runners.size(); j++){
            long long int where = (photos[i].u - runners[j].first) * runners[j].second;
            if(where >= photos[i].a && where <= photos[i].b){
                photos[i].trash = 0;
                break;
            }       
        }
    }

    //pra cada queue testar se na foto ruim não aparece o Johnny
    for(unsigned long long int i = 0; i < queues.size(); i++){
        long long int t = 0;
        for(unsigned long long int j = 0; j < photos.size(); j++){
            if(photos[j].trash){
                t++;
            } else {
                continue;
            }

            long long int where = (photos[j].u - queues[i].first) * queues[i].second;
            if(where >= photos[j].a && where <= photos[j].b){
                t--;
            }       
        }
        cout << t << endl;
    }

    return 0;
}