#include <bits/stdc++.h>
using namespace std;
#define SIZE 1003

int n, m, arr[SIZE], ind[SIZE];
vector<int> adj[SIZE], res;
queue<int> q;

int main() {
    scanf("%d %d", &n, &m);
    while(m--){
        int o;
        scanf("%d", &o);
        for(int i=0; i<o; i++)
            scanf("%d", &arr[i]);
        for(int i=0; i< o - 1; i++){
            adj[arr[i]].push_back(arr[i+1]);
            ind[arr[i+1]]++;
        }
    }
    for(int i=1; i<=n; i++){
        if(!ind[i])
            q.push(i);
    }
    while(!q.empty()){
        int now = q.front();
        q.pop();
        res.push_back(now);
        for(int nxt : adj[now]){
            ind[nxt]--;
            if(!ind[nxt])
                q.push(nxt);
        }
    }
    if(res.size() == n){
        for(int x : res){
            printf("%d\n", x);
        }
    } else {
        printf("0\n");
    }
    return 0;
}