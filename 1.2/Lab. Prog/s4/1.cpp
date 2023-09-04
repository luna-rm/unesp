#include<bits/stdc++.h> 

using namespace std;

int main() {
    while(1){
        int how_many, ansr = 0;
        cin >> how_many;
        if(!how_many){
            break;
        }

        vector<int> vec;

        while (how_many--) {
            int aux;
            cin >> aux;
            vec.push_back(aux);
        }

        int init = vec[0], end = vec.back() + 0;
        vec.insert(vec.begin(), end);
        vec.push_back(init);          


        for(unsigned int i = 1; i < vec.size()-1; i++){
            if(vec[i] > vec[i-1] && vec[i] > vec[i+1]){
                ansr++;
            }

            if(vec[i] < vec[i-1] && vec[i] < vec[i+1]){
                ansr++;
            }
        }

        cout << ansr << endl;

    }

    return 0;
}