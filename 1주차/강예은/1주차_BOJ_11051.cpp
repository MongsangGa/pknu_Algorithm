#include <bits/stdc++.h>

using namespace std;
//몰라서 파스칼 어쩌구 설명보고 풀기시작

#define mod 10'007
int dp[1001][1001];

void fibo (int n, int k){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=k; j++){
            if(i==j || j==0)
            dp[i][j] = 1;
            else
            dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % mod;
        }
    }
}
int main () {
    int n, k;
    scanf("%d %d", &n, &k);
    fibo(n, k);
    printf("%d", dp[n][k]);
    return 0;
}