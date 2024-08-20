#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(n + 1, vector<int>(m + 1));
	queue<pair<int, int>> qu;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) scanf("%1d", &v[i][j]);
	}

	qu.push({ 0,0 });
	v[0][0] = 2;

	while (!qu.empty()) {
		int x = qu.front().first,y=qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];

			if ((0 <= dxx && dxx < n && 0 <= dyy && dyy < m) && v[dxx][dyy] == 1) {
				v[dxx][dyy] = v[x][y] + 1;
				qu.push({ dxx,dyy });
			}
		}
	}

	cout << v[n-1][m-1] - 1;
	return 0;
}
