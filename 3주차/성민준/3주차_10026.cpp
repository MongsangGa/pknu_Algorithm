#include <bits/stdc++.h>
using namespace std;

int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };

class node {
public:
	char c;
	int visit = 0;
};

bool inrange(int a, int b, vector<vector<node>>& v) {
	return 0 <= a && a < v.size() && 0 <= b && b < v.size();
}

void bfs(int a, int b, int k, vector<vector<node>>& v) {
	v[a][b].visit = k;
	queue<pair<int, int>> qu;
	qu.push({ a,b });

	while (!qu.empty()) {
		int x = qu.front().first, y = qu.front().second;
		qu.pop();

		for (int i = 0; i < 4; i++) {
			int dxx = x + dx[i], dyy = y + dy[i];

			if (inrange(dxx, dyy, v) && v[dxx][dyy].c == v[x][y].c && v[dxx][dyy].visit == 0) {
				v[dxx][dyy].visit = k;
				qu.push({ dxx,dyy });
			}
		}
	}
}

void clean_recoloring(vector<vector<node>>& v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			v[i][j].visit = 0;
			if (v[i][j].c == 'R') v[i][j].c = 'G';
		}
	}
}

void bfsmanage(int n, vector<vector<node>>& v) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].visit == 0) {
				bfs(i, j, ++k, v);
			}
		}
	}
	cout << k << " ";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k = 1;
	cin >> n;
	vector<vector<node>> v(n, vector<node>(n));

	for (int i = 0; i < n * n; i++) {
		cin >> v[i / n][i % n].c;
	}

	bfsmanage(n, v);
	clean_recoloring(v);
	bfsmanage(n, v);
	return 0;
}
