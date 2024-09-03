#include <bits/stdc++.h>
using namespace std;

#define SIZE 503

int n, m, vis[SIZE];
bool isTree;
vector<int> adj[SIZE];

void DFS(int now, int prev){
    vis[now]=1;
    for(auto nxt:adj[now]){
        if(nxt==prev) continue;
        //사이클 여부
        if(vis[nxt]){
            isTree=false;
            continue;
        }
        DFS(nxt, now);
    }
}

int main(){
    int index=0;
    while(1){
        index++;
        scanf("%d %d", &n, &m);
        if(!n && !m) break;

        // 간선, 방문지배열 초기화
        for(int i=1;i<SIZE;i++)
            adj[i].clear();
        fill(vis, vis+SIZE, 0);

        // 간선 입력
        while(m--){
            int x, y;
            scanf("%d %d", &x, &y);

            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        int res=0;
        for(int i=1;i<=n;i++){
            isTree=true;
            DFS(i, -1);
            res+=isTree;
        }

        if(res==0) printf("Case %d: No trees.\n", index);
        else if(res==1) printf("Case %d: There is one tree.\n", index);
        else printf("Case %d: A forest of %d trees.\n", index, res);
    }

    return 0;
}