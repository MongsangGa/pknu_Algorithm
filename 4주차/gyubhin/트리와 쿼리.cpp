#include <bits/stdc++.h>

using namespace std;

#define SIZE 100'002

int n, r, q, cnt[SIZE];
bool vis[SIZE];
vector<int> adj[SIZE];

//DFS
int DFS(int now) {
	vis[now] = true;
	cnt[now] = 1;
	for (auto nxt : adj[now]) {
		if (!vis[nxt]) cnt[now] += DFS(nxt);
	}
	return cnt[now];
}

int main(void) {
	int x, y, u;
	scanf("%d %d %d", &n, &r, &q);
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &x, &y);
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	DFS(r);

	for (int i = 0; i < q; i++) {
		scanf("%d", &u);
		printf("%d\n", cnt[u]);
	}


	return 0;
}