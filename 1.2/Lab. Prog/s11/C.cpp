#include<bits/stdc++.h> 

using namespace std;

int main() {
    string sentence, word;
    cin >> sentence >> word;

    int ansr = 0;
    for(unsigned int i = 0; i < sentence.size() - word.size() + 1; i++){
        int found = 1;
        for(unsigned int j = i; j < word.size()+i; j++){
            if(word[j-i] == sentence[j]){
                found = 0;
            }
        }
        if(found){
            ansr++;
        }
    }
    cout << ansr << endl;
    
    return 0;
}