#include<bits/stdc++.h> 

using namespace std;

int main() {
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i*i <= n; i++){
            if(i > 1 && i*i < n){
                printf(" ");
            }
            printf("%d", i*i);
        }
        printf("\n");
    }

    return 0;
}