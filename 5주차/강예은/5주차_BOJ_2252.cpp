#include <bits/stdc++.h>
using namespace std;
#define SIZE 100'000

int n, m, ind[SIZE];
vector<int> adj[SIZE];
queue<int> q;

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b;
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    ind[b]++;
    }
    for(int i=1; i<= n; i++)
        if (!ind[i])
            q.push(i);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        printf("%d ", cur);
        for (auto nxt: adj[cur]) {
            ind[nxt]--;
            if (!ind[nxt]) q.push(nxt);
        }
    }
    return 0;
}