#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'002

int n, vis[SIZE];//노드, 간선 방문지
vector<int> adj[SIZE]; //간선벡터: 사이즈 만큼 벡터 행이 만들어짐
int parent[SIZE];// 부모노드 저장 배열

void DFS(int now, int par){
    vis[now] = 1;
    parent[now] = par;// 부모노드로 설정

    for(auto nxt : adj[now]){
        if(vis[nxt] == 1) continue;
        DFS(nxt, now); // 자식 노드로 DFS를 재귀호출(now 가 nxt의 부모가 된다)
        
    }
}
/* for(int i=0; i < adj[now].size(); i++){
       int nxt = adj[now][i];
}*/

int main(){
    fastio;
    cin >> n;
    for (int i =0; i < n-1; i++){// n-1개 간선
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y); // x 벡터에 y 값을 넣음
        adj[y].push_back(x); // y 벡터에 x 값을 넣음

    }

    DFS(1, -1);// 루트노드인 1부터 DFS 시작

    for(int i =1; i <= n; i++){
        if(parent[i] != -1){// 루트노드가 아니라면
            cout << parent[i] << '\n';// 부모노드 출력
        }
    }

    
}