#include<bits/stdc++.h> 

using namespace std;

struct input{
    char letter;
    int how_many = 1;
};


int main() {
    int cases;
    cin >> cases;

    for(int i = 0; i < cases; i++){
        int R, C, M, N;
        cin >> R >> C >> M >> N;

        vector<input> v;
        for(int j = 0; j < R; j++){
            string aux;
            cin >> aux;

            for(unsigned int l = 0; l < aux.size(); l++){
                int is_there = 0;
                for(unsigned int k = 0; k < v.size(); k++){
                    if(aux[l] == v[k].letter){
                        v[k].how_many++;
                        is_there = 1;
                    }
                } 
                if(!is_there){
                    input aux_input;
                    aux_input.letter = aux[l];
                    v.push_back(aux_input);
                }
            }         
        }

        int imp = -1, hm = 0;
        for(unsigned int j = 0; j < v.size(); j++){
            if(v[j].how_many > imp){
                imp = v[j].how_many;
                hm = 1;
            } else if(v[j].how_many == imp){
                hm++;
            }
        }

        int res = hm*imp*M;
        for(unsigned int j = 0; j < v.size(); j++){
            if(v[j].how_many != imp){
                res += v[j].how_many*N;
            }
        }

        cout << "Case " << i+1 << ": " << res << endl;
    }

    return 0;
}