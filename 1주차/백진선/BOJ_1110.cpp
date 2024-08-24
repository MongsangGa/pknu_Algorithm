#include <bits/stdc++.h>
using namespace std;

int N, n1, n2;

int main(){
    scanf("%d", &N);

    int NewN=N;
    int NewNum=-1, cnt=0;

    while(N!=NewNum){
        n1 = NewN/10;
        n2 = NewN%10;
        NewN = n1+n2;
        
        NewNum = n2*10+NewN%10;
        NewN = NewNum;

        cnt++;
    }

    printf("%d", cnt);

    return 0;
}