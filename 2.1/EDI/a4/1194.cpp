#include<bits/stdc++.h> 

using namespace std;

void coolest_tree(string pre, string in, int begin, int end, int *i){
    int mid = in.find(pre[*i]);
    char aux = pre[*i];
    (*i)++;
    if (mid -  begin){
        coolest_tree(pre, in, begin, mid-1, i);
    }
    if (end - mid){
        coolest_tree(pre, in, mid+1, end, i);
    }
    cout << aux;   
}

int main() {
    string pre;
    while(cin >> pre){
        string in;
        cin >> in;
        int i = 0;

        coolest_tree(pre, in, 0, pre.size()-1, &i);
        cout << endl;
    }

    return 0;
}