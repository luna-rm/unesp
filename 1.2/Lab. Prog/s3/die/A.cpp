#include<bits/stdc++.h> 

using namespace std;


int main() {

    int cases;
    cin >> cases;
    cin.ignore();

    vector<pair<char, int>> v = {{'b', 1}, {'c', 2}, {'e', 1}, {'f', 2}, {'h', 1}, {'i', 2}, {'k', 1}, {'l', 2}, {'n', 1}, {'o', 2}, {'q', 1}, {'r', 2}, {'s', 3}, {'u', 1}, {'v', 2}, {'x', 1}, {'y', 2}, {'z', 3}};

    for(int c = 1; c < cases+1; c++){
        string line;
        getline(cin, line);

        int h = 0;
        for(unsigned int i = 0; i < line.size(); i++){
            h++;
            for(unsigned int j = 0; j < v.size(); j++){             
                if(line[i] == v[j].first){
                    h += v[j].second;
                    break;
                }
            }
        }
        cout << "Case #" << c << ": " << h << endl;
    }

    return 0;
}