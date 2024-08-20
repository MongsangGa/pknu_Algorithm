#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n, m, cnt = 0;

class node {
public:
	int h = 0;
	int cnt = 0;
	int visit = 0;
};

bool inrange(int a, int b) {
	return 0 <= a && a < n && 0 <= b && b < m;
}

void dfs(int a, int b, vector<vector<node>>& v) {
	v[a][b].visit = 1;
	for (int i = 0; i < 4; i++) {
		int x = a + dx[i], y = b + dy[i];

		if (inrange(x, y) && v[x][y].h < v[a][b].h) {
			if (v[x][y].visit == 0) dfs(x, y, v);
			v[a][b].cnt += v[x][y].cnt;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	vector<vector<node>> v(n, vector<node>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j].h;
		}
	}

	v[n - 1][m - 1].cnt = v[n - 1][m - 1].visit = 1;
	dfs(0, 0, v);

	cout << v[0][0].cnt;
	return 0;
}
