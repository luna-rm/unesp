#include<bits/stdc++.h> 

using namespace std;

int main() {
    FILE * arq = fopen("text.txt", "w");
    string text;

    if(!arq){
        cout << ":(" << endl;
        exit(1);
    }

    getline(cin, text);
    while(text.size() != 0){
        fputs(text.c_str(), arq);
        putc('\n', arq);
        getline(cin, text);
    }

    fclose(arq);
    
    return 0;
}