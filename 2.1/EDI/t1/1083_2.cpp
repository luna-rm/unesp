#include<bits/stdc++.h> 

using namespace std;

stack <char> ansr;
string text;

int find_next(int start, int end){
    for(int i = start; i < end; i++){
        cout << text[i] << endl;
        if(text[i] == ')'){
            cout << "AAAA" << endl;
            return 0;
        }

        if(text[i] == '('){
            int found = 0;
            for(int j = start; j < end; j++){
                if (text[j] == ')'){
                    if(!find_next(i+1, j-1)){
                        return 0;
                    }
                    found = 1;
                    start = j+1;
                    break;
                }
            }
            if(!found){
                cout << "BBBBB" << endl;
                return 0;
            }
        }
    }

    for(int i = start; i < end; i++){

    }

    return 1;
}



int main() {
    string ops = {'(', ')', '^', '*', '/', '+', '-', '>', '<', '=', '#', '.', '|'};
    while(cin >> text){
        int stop = 0;
        for(unsigned int i = 0; i < text.size(); i++){
            int is_right = 0;
            if (ops.find(text[i]) < ops.size()){
                is_right = 1;
            } else if (text[i] >= 'a' && text[i] <= 'z'){
                is_right = 1;
            } else if (text[i] >= 'A' && text[i] <= 'Z'){
                is_right = 1;
            }
            if(!is_right){
                cout << "Lexical Error!" << endl;
                stop = 1;
                break;
            }
        }

        if(stop){
            continue;
        }

        if(!find_next(0, text.size())){
            cout << "Syntax Error!" << endl;
        }

    }

    return 0;
}