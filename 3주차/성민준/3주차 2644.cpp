#include <bits/stdc++.h>
using namespace std;

class node {
public:
	vector<int> edge;
	int visit = 0;
	int chon = -1;
};

void dfs(int k, vector<node>& v) {
	stack<int> stc;
	v[k].visit = 1;
	v[k].chon = 0;
	stc.push(k);

	while (!stc.empty()) {
		int a = stc.top();
		stc.pop();

		for (auto i : v[a].edge) {
			if (v[i].visit == 0) {
				v[i].visit = 1;
				v[i].chon = v[a].chon + 1;
				stc.push(i);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, a, b, m;
	cin >> n >> a >> b >> m;
	vector<node> v(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].edge.push_back(b);
		v[b].edge.push_back(a);
	}

	dfs(a, v);
	cout << v[b].chon;
	return 0;
}
