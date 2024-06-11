#include<bits/stdc++.h> 

using namespace std;


int binary_search(int dir, int esq, int num, vector<int> vec, int how_many){
    int mid = (dir + esq)/2;

    if(num-1 == vec[mid] || num == vec[mid]){
        return -1;
    } else if(num+1 == vec[mid]){
        return mid;
    } else if((unsigned int) how_many > vec.size()){
        return -2;
    } else if(num < vec[mid]){
        return binary_search(dir, mid, num, vec, how_many+1);
    } else {
        return binary_search(mid, esq, num, vec, how_many+1);
    }
}

int main() {
    int n;
    cin >> n;
    while(n--){
        int n2, die = 0;
        cin >> n2;

        vector<int> vec;
        while(n2--){
            int aux;
            cin >> aux;
            
            if(vec.size() < 1) {
                vec.push_back(aux);
                continue;
            } 

            int res = binary_search(0, vec.size(), aux, vec, 0);

            if(res == -2){
                die++;
            } else if(res != -1) {
                vec.erase(vec.begin() + res);
                vec.push_back(aux);
            }
        }

        if(!die){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}