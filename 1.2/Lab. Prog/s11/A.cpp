#include<bits/stdc++.h> 

using namespace std;

int main() {
    string word;
    cin >> word;

    for(unsigned int i = 0; i < word.size(); i++){
        char aux = tolower(word[i]);
        if(aux == 'a' || aux == 'e' || aux == 'i' || aux == 'o' || aux == 'u' || aux == 'y'){
            continue;
        }

        cout << "." << aux;
    }

    cout << endl;

    return 0;
}