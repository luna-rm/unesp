#include<bits/stdc++.h> 

using namespace std;

string c2to10(string num){
    double ansr_num = 0;

    for(int i = num.size()-1; i >= 0; i--){        
        if(num[i] == '1'){
            ansr_num += pow(2.0, (double) num.size()-1-i);
        }
    }

    string ansr = to_string((int)ansr_num);
    return ansr;
}

string c10to2(string num){
    
    int num_aux = 0;
    for(int i = num.size()-1; i >= 0; i--){        
        num_aux += (int)pow(10.0, num.size()-1-i);
    } 

    

    return ansr;
}

string c10to16(string num){
        
    return ansr;
}

string c16to10(string num){
        
    return ansr;
}

int main() {

    string num;
    int type;
    int to;
    
    cout << "numero: ";
    getline(cin, num);

    cout << num;
    
    cout << endl << "tipo: ";
    cin >> type;

    cout << endl << "para: ";
    cin >> to;

    //system("cls");

    if(type == 2){
        if(to == 10){
            cout << c2to10(num);
        } else {
            cout << "no";
            return 0;
        }
    } else if(type == 10){
        if(to == 2){
            cout << c10to2(num);
        } else if(to == 16){
            cout << c10to16(num);
        } else {
            cout << "no";
            return 0;
        }
    } else if(type == 16){
        if(to == 10){
            cout << c16to10(num);
        } else {
            cout << "no";
            return 0;
        }
    } 

    return 0;
}