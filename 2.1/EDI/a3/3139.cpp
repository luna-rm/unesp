#include<bits/stdc++.h> 

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long int at, to;
    cin >> at >> to;
    int aux;

    long int total = 0;
    queue<int> days;
    for(int i = 0; i < 30; i++){
        cin >> aux;
        total += aux;
        days.push(aux);
    }
    //cout << total << endl;

    long int day = 0;
    while(at < to){
        //cout << at << endl;
        day++;
        long int add = ceil(total / 30.0);
        //cout << add << endl;
        at += add;
        total -= days.front();
        total += add;
        days.pop();
        days.push(add);
    }

    cout << day << endl;

    return 0;
}