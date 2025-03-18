#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    priority_queue<int> p;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        p.push(a);
    }

    int r;
    while(n--){
        int a = p.top();
        p.pop();

        if(k % a == 0){
            r = (int) (k/a);
            break;
        }
    }
    cout << r << endl;

    return 0;
}