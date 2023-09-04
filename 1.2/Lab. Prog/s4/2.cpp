#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vec;

    while(n--){
        int aux, no = 0;
        cin >> aux;
        int size = vec.size();
        for(int i = 0; i < size; i++){
            if(vec[i].first == aux){
                vec[i].second++;
                no = 1;
                break;
            } else if(vec[i].first > aux){
                vec.insert(vec.begin()+i, pair<int, int>({aux, 1}));
                no = 1;
                break;
            }
        }

        if(!no){            
            vec.push_back(pair<int, int>({aux, 1}));
        }
    }

    for(unsigned int i = 0; i < vec.size(); i++){
        cout << vec[i].first;
        cout << " aparece ";
        cout << vec[i].second;
        cout << " vez(es)" << endl;
    }

    return 0;
}