#include<bits/stdc++.h> 

using namespace std;

int main() {

    string text;
    set<string> dict;  
    while(cin >> text){
        string word = "";
        int added = 0;
        for(unsigned int i = 0; i < text.length(); i++){
            char l = tolower(text[i]);
            if(l >= 'a' && l <= 'z'){
                word += l;
                added = 0;
            } else {
                if(word != ""){
                    dict.insert(word);
                }
                word = "";
                added = 1;
            }
        }  
        
        if(!added){
            if(word != ""){
                dict.insert(word);
            }
        }
        
        /* for(string e : dict){
            cout << e << endl;
        } */
        
    }

    //dict.erase(0);

    for(string e : dict){
        cout << e << endl;
    }

    return 0;
}