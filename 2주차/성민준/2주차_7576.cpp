#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

bool inrange(int a, int b, int n, int m) {
	return 0 <= a && a < n && 0 <= b && b < m;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, cnt = 0;
	cin >> m >> n;
	vector<vector<int>> v(n, vector<int>(m));
	queue<pair<int, int>> qu;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			if (v[i][j] == 1) qu.push({ i,j }), cnt++;
			else if (v[i][j] == -1) cnt++;
		}
	}

	int fx = qu.front().first, fy = qu.front().second; //마지막으로 방문하는 위치를 저장(그러면 최대 일수 표현가능)
	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];

			if (inrange(dxx, dyy, n, m) && v[dxx][dyy] == 0) {
				cnt++;
				v[dxx][dyy] = v[x][y] + 1;
				qu.push({ dxx,dyy });
				fx = dxx, fy = dyy;
			}
		}
	}

	if (cnt != n * m) cout << -1;
	else cout << v[fx][fy] - 1;
	return 0;
}
