#include <bits/stdc++.h>
using namespace std;

int arr[9], sum;

void f(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i==j) continue;
            if(sum-(arr[i]+arr[j])==100){
                arr[i]=arr[j]=-1;
                return;
            }
        }
    }
}

int main(){
    for(int i=0;i<9;i++){
        scanf("%d", &arr[i]);
        sum+=arr[i];
    }
    f();
    sort(arr, arr+9);
    for(int i=2;i<9;i++){
        printf("%d\n", arr[i]);
    }
    return 0;
}