#include<bits/stdc++.h> 

using namespace std;

void fib(int n, int vet[]){
    vet[0] = vet[1] = 1;

    for(int i = 2; i < n; i++){
        vet[i] = vet[i-1] + vet[i-2];
    }
}

int main() {
    int vet[44];
    int n;

    cin >> n;

    fib(n, vet);

    for(int i = n-1; i >= 0; i--){
        cout << vet[i];

        if(i == 0){
            cout << endl; 
        } else {
            cout << " ";
        }
    }

    return 0;
}