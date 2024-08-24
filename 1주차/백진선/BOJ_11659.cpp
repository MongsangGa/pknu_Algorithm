#include <bits/stdc++.h>
using namespace std;

#define SIZE 100'007

int main(){
    int arr[SIZE], N, M, psum[SIZE];
    scanf("%d %d", &N, &M);

    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }

    psum[0]=arr[0];
    for(int i=1;i<N;i++){
        psum[i]=psum[i-1]+arr[i];
    }

    int n1,n2, sum[M];
    for(int i=0;i<M;i++){
        scanf("%d %d", &n1, &n2);
        sum[i] = psum[n2-1]-psum[n1-2];
    }

    for(int i=0;i<M;i++)
        printf("%d\n", sum[i]);
    
    /*for(int i=0;i<N;i++){
        printf("%d ", psum[i]);
    }*/

    return 0;

}