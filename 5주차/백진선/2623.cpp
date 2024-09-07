#include <bits/stdc++.h>
using namespace std;

#define SIZE 1005

int n, m, ind[SIZE];
int res[SIZE];
vector<int> adj[SIZE];
queue<int> q;

int main(){
    scanf("%d %d", &n, &m);

    while(m--){
        int num;
        vector<int> arr;
        scanf("%d", &num);
        arr.resize(num);
        
        for(int i=0;i<num;i++){
            scanf("%d", &arr[i]);
        }
        
        for(int i=0;i<num-1;i++){
            adj[arr[i]].push_back(arr[i+1]);
            ind[arr[i+1]]++;
        }
    }

    for(int i=1;i<=n;i++){
        if(!ind[i]) q.push(i);
    }

    
    int index=0;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        //printf("%d ", now);
        res[index] = now;
        index++;

        for(auto nxt:adj[now]){
            ind[nxt]--;
            if(!ind[nxt]) q.push(nxt);
        }
    }

    /*printf("\n");
    for(int i=0;i<n;i++){
            printf("%d ", res[i]);
    }
    printf("\n");*/
    

    if(index!=n){
        printf("0\n");
    } else{
        for(int i=0;i<n;i++){
            printf("%d\n", res[i]);
        }
    }

    return 0;
}