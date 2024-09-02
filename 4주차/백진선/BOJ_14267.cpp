#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr, res;

void good(int i, int w){
    res[i] += w;

    for(int ind = 0; ind < n; ind++){
        if(arr[ind] > arr[i]) {
            res[ind] += w;
        }
    }
}

int main(){
    scanf("%d %d", &n, &m);
    arr.resize(n);
    res.resize(n, 0);

    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    while(m--){
        int i, w;
        scanf("%d %d", &i, &w);
        i--;
        good(i, w);
    }

    for(int i = 0; i < n; i++){
        printf("%d ", res[i]);
    }

    return 0;
}
