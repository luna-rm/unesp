#include<bits/stdc++.h> 

using namespace std;

int main() {
    FILE * arq = fopen("text.txt", "r");
    char character;

    if(!arq){
        cout << ":(" << endl;
        exit(1);
    }

    do {
        character = getc(arq);
        cout << character;
    } while(character != EOF);

    return 0;
}