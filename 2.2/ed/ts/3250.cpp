#include<bits/stdc++.h> 

using namespace std;

int main() {
    int floors, start, goal, up, down, now, count=0;
    cin >> floors >> start >> goal >> up >> down;
    now = start;

    while(goal>now && up!=0){
        now+=up;
        count++;
    }

    while(goal<now && down!=0){
        now-=down;
        count++;
    }

    while(goal>now && up!=0){
        now+=up;
        count++;
    }

    if(now == goal){
        cout << count << endl;
    }else{
        cout << "use the stairs" << endl;
    }

    return 0;
}