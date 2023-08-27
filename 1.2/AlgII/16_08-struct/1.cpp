#include<bits/stdc++.h> 

using namespace std;

struct hm {
    int hours = 0;
    int min = 0;
};

int main() {
    hm ansr;
    cin >> ansr.min;

    while(ansr.min / 60 >= 1){
        ansr.hours += 1;
        ansr.min -= 60;
    }

    cout << "hours: " << ansr.hours << endl << "min: " << ansr.min;

    return 0;
}