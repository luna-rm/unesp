#include<bits/stdc++.h> 

using namespace std;

int main() {
    int num;
    scanf("%d", &num);
    deque <int> queue;
    while(num--) {
        int dir = 0;
        char str[100];
        scanf("%s", str);

        if(!strcmp(str, "back")) {
            if(queue.empty()) {
                printf("No job for Ada?\n");
            }
            else {
                if(!dir) {
                    cout << queue.front() << endl;
                    queue.pop_front();
                }
                else {
                    cout << queue.back() << endl;
                    queue.pop_back();
                }
            }
        }
        else if(!strcmp(str, "front")) {
            if(queue.empty()) {
                printf("No job for Ada?\n");
            }
            else {
                if(!dir) {
                    cout << queue.back() << endl;
                    queue.pop_back();
                }
                else {
                    cout << queue.front() << endl;
                    queue.pop_front();
                }
            }
        }
        else if(!strcmp(str, "reverse")){
            if(dir){
                dir = 0;
            } else {
                dir = 1;
            }
        }
        else if(!strcmp(str, "push_back")) {
            int aux;
            cin >> aux;
            if(dir){
                queue.push_front(aux);
            }
            else{
                queue.push_back(aux);
            } 
        }
        else if(!strcmp(str, "toFront")) {
            int aux;
            cin >> aux;
            if(dir){
                queue.push_back(aux);
            }
            else{
                queue.push_front(aux);
            } 
        }
    }
}