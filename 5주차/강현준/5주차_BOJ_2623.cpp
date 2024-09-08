#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 1002
#define M_SIZE 102

int n, m, arr[SIZE], ind[SIZE];
vector<int> adj[M_SIZE];  
queue<int> q;

int main(){
    fastio;

    cin >> n >> m;

    while (m--){
        int num;
        cin >> num;
        for(int i = 0; i < num; i++) cin >> arr[i];
        
        adj[arr[i]].push_back();
        ind[]++;

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



    
}