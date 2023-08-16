#include<bits/stdc++.h> 

using namespace std;

int main() {

    char word1[24], word2[24];


    cin >> word1 >> word2;

    if(strcmp(word1, word2) > 0){
        cout << word2 << endl;
        cout << word1 << endl;        
    }

    if(strcmp(word1, word2) < 0){
        cout << word1 << endl;
        cout << word2 << endl;        
    }

    return 0;
}