#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--){
        string str;
        cin >> str;
        int ans = 0;
        int dia = 0;
        fflush(stdin);
        for(unsigned int i = 0; i < str.size(); i++){
            if(str[i] == '<'){
                dia++;
            }
            if(str[i] == '>'){
                dia--;
                if(dia < 0){
                    dia = 0;
                    continue;
                }
                ans++;
            }
        }
        cout << ans << endl;        
    }

    return 0;
}