def hanoi

void hanoi(int n, int O, int A, int D){
    if(n == 0)
        return;
    hanoi(n-1,O,D,A);
    cout << O << " " << D << endl;
    hanoi(n-1,A,O,D);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin​ >> n;
    cout << pow(2,n)-1 << endl;
    hanoi(n,1,2,3);
}