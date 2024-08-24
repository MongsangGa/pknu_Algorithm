#include <bits/stdc++.h>
using namespace std;

int N, K;

int f(int n, int k, int index){
    if(k==0){
        return 1;
    }
    if(index==n){
        return 0;
    }
    
    int cnt = 0;
    if(k>=0){
        cnt += f(n, k, index+1);
        cnt += f(n, k-1, index+1);
    }

    return cnt;
}


int main(){
    scanf("%d %d", &N, &K);

    int cnt = f(N, K, 0);

    int result = cnt%10007;
    printf("%d", result);

    return 0;
}