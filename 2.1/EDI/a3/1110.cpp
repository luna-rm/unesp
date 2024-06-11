#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    cin >> n;
    while(n){
        queue<int> cards;
        for(int i = 0; i < n; i++){
            cards.push(i+1);
        }
        cout << "Discarded cards:"; 
        int first = 1;
        while(cards.size() != 1){
            if(first){
                cout << " " << cards.front();
                first = 0;
            } else {
                cout << ", " << cards.front();
            }
            cards.pop();
            cards.push(cards.front());
            cards.pop();
        }
        cout << endl << "Remaining card: " << cards.front() << endl;

        cin >> n;

    }


    return 0;
}