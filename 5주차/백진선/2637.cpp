#include <bits/stdc++.h>
using namespace std;
#define SIZE 103

int n, m, ind[SIZE];
vector<pair<int, int>> adj[SIZE];
queue<int> q;

int main(){
    scanf("%d", &n);
    scanf("%d", &m);

    while(m--){
        int mid, basic, num;
        scanf("%d %d %d", &mid, &basic, &num);
        adj[mid].push_back({basic, num});
        ind[basic]++;
    }

    for(int i=1;i<=n;i++){
        if(!ind[i]) q.push(i);
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto nxt:adj[now]){
            ind[nxt.first]--;
            if(!ind[nxt.first]) q.push(nxt.first);
            //printf("%d %d\n", nxt.first, nxt.second);
        }
    }

    return 0;
}