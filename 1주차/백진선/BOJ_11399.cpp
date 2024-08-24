#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000

int N;
int arr[SIZE];
vector<int> sum;

int main(){
    scanf("%d", &N);
    
    sum.resize(N);
    for(int i=0;i<N;i++){
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+N);

    sum[0]=arr[0];
    for(int i=1;i<N;i++){
        sum[i]= sum[i-1]+arr[i];
    }

    int total=0;
    for(int i=0;i<N;i++){
        total += sum[i];
    }
    printf("%d", total);


    return 0;
}