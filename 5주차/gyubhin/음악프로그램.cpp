#include <bits/stdc++.h>

using namespace std;
#define SIZE 1'002

int n, m, ind[SIZE], arr[SIZE], cnt=0, result[SIZE];
vector<int> adj[SIZE];
queue<int> q;

int main(void) {
    int x;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        for (int j = 0; j < x; j++) {
            scanf("%d", &arr[j]);
        }
 
        for (int j = 0; j < x - 1; j++) {
            adj[arr[j]].push_back(arr[j + 1]);
            ind[arr[j+1]]++;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!ind[i]) q.push(i);
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        arr[cnt] = cur;
        cnt++;
        for (auto nxt : adj[cur]) {
            ind[nxt]--;
            if (!ind[nxt]) q.push(nxt);
        }
    }

    if (cnt != n) printf("0");
    else 
        for (int i = 0; i < n; i++) {
            printf("%d\n", arr[i]);
        }

    return 0;
}