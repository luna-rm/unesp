#include<bits/stdc++.h> 

using namespace std;


int main() {
    (ios_base:: sync_with_stdio(false),cin.tie(NULL));
    int n;
    cin >> n;
    while(n--){
        string s, t;
        cin >> s >> t;

        int ansr = 0;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(unsigned int i = 0; i < s.size(); i++){
            for(unsigned int j = 0; j < t.size(); j++){
                if(t.find(s[i]) <= s[i]){
                    ansr++;
                    break;
                }
            }
            if(ansr){
                break;
            }
        }

        if(ansr == 0){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}