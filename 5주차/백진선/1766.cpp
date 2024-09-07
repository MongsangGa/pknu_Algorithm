#include <bits/stdc++.h>
using namespace std;

#define SIZE 32002

int n, m, ind[SIZE];
vector<int> adj[SIZE];
priority_queue<int, vector<int>, greater<int>> q;

int main(){
    scanf("%d %d", &n, &m);

    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        ind[b]++;
    }

    for(int i=1;i<=n;i++){
        if(!ind[i]) q.push(i);
    }

    while(!q.empty()){
        int now=q.top();
        q.pop();
        printf("%d ", now);
        for(auto nxt:adj[now]){
            ind[nxt]--;
            if(!ind[nxt]) q.push(nxt);
        }
    }


    return 0;
}