#include <bits/stdc++.h>
using namespace std;

#define SIZE 102

int n, m, vis[SIZE];
vector<int> adj[SIZE];
int res=0;


int DFS(int now){
    // 방문지 체크
    vis[now] = 1;
    res++;

    // 탐색
    for(auto nxt : adj[now]){
        if(vis[nxt]) continue;
        DFS(nxt);
    }

    return 0;

}


int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        int x, y;
        scanf("%d %d", &x, &y);
        //연결
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    DFS(1);

    printf("%d", res-1);

    return 0;
}