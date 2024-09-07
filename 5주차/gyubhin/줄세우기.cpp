#include <bits/stdc++.h>

using namespace std;
#define SIZE 100002

int n, m, ind[SIZE];
vector<int> adj[SIZE];
queue<int> q;

int main(void) {
	int u, v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		ind[v]++;
	}

	for (int i = 1; i <= n; i++) {
		if (!ind[i]) q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		printf("%d ", cur);
		for (auto nxt : adj[cur]) {
			ind[nxt]--;
			if (!ind[nxt]) q.push(nxt);
		}
	}
	return 0;
}