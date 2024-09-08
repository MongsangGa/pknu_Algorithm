#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define N_SIZE 32001
#define M_SIZE 100'001

int n, m, ind[N_SIZE];
vector<int> adj[M_SIZE];  
queue<int> q;

int main(){
    fastio;

    cin >> n >> m;

    while (m--){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        ind[b]++;
    }

    for(int i = 1; i <= n; i++){
        if(!ind[i])
            q.push(i);
    }
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';
        
        for (auto nxt: adj[cur]){
            ind[nxt]--;
            if(!ind[nxt]) q.push(nxt);
        }
    }
    
    return 0;
}