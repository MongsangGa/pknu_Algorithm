#include <bits/stdc++.h>
using namespace std;

#define SIZE 1005

int n, m, sNode, eNode, vis[SIZE];
vector<pair<int, int>> adj[SIZE];
bool found;

void DFS(int now, int prev, int res){
    if(found) return ;
    vis[now]=1;
    if(now==eNode){
        printf("%d", res);
        found = true;
        return ;
    }

    for(auto nxt : adj[now]){
        int nxtN = nxt.first;
        int nxtC = nxt.second;
        if(vis[nxtN] || prev == nxtN) continue;
        DFS(nxtN, now, res + nxtC);
    }

}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=1;i<n;i++){
        int x, y, distance;
        scanf("%d %d %d", &x, &y, &distance);

        adj[x].push_back({y, distance});
        adj[y].push_back({x, distance});
        
    }
    
    for(int i=0;i<m;i++){
        scanf("%d %d", &sNode, &eNode);
        fill(vis, vis+SIZE, 0);
        found=false;
        DFS(sNode, -1, 0);
    }

    return 0;
}