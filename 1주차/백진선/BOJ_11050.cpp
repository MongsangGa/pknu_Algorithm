#include <bits/stdc++.h>
using namespace std;

int N, K;

int factorial(int n){
    int result = 1;
    for(int i=n;i>0;i--){
        result*=i;
    }
    return result;
}

int main(){
    scanf("%d %d", &N, &K); //전체 N개 중 K개 뽑 =: nCk

    int result = factorial(N)/(factorial(K)*factorial(N-K));
    printf("%d", result);

    return 0;
}