#include<bits/stdc++.h> 

using namespace std;

int main() {

    int n, w;
    cin >> n >> w;
    
    int mat[w+1][n];
    priority_queue <pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> prio;
    vector<pair<long long int, long long int>> prio_aux;
    
    for(int i = 0; i < n; i++){
        long long int aux_w, aux_v;
        cin >> aux_w >> aux_v;
        prio.push({aux_w, aux_v});
    }

    for(int j = 0; j < n; j++){
        pair<long long int, long long int> item = prio.top();
        prio_aux.push_back(item);
        prio.pop();

        for(int i = 0; i < w+1; i++){
            int aux = 0;
            int weight = i - item.first;

            if(weight >= 0){
                aux = item.second;
            }

            if(j){
                int k = j-1;
                for(k = j-1; k > 0; k--){
                    if(mat[weight+1][j-1] != mat[weight+1][k]){
                        k += 1;
                        break;
                    }
                }
                weight -= prio_aux[k].first;
                if(weight >= 0){
                    aux += prio_aux[k].second;
                }
            
                if(aux <= mat[i][j-1]){
                    aux = mat[i][j-1];
                    if(weight >= item.first-1){
                        aux = mat[i-weight][j-1] + item.second;
                    }
                }
            }

            mat[i][j] = aux;
            cout << aux << " ";
        }    
        cout << endl;
    }

    cout << mat[w][n-1] << endl;
    

    return 0;
}