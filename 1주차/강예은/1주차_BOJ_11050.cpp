#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, K, sum = 1;
    scanf("%d %d",&N, &K);

    for(int i = 0; i < K; i++){
        sum *= N;
        N--;
    }
    for(int i = K; i > 0; i--){
        sum /= i;
    }
    printf("%d", sum);
    return 0;
}