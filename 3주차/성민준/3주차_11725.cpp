#include <bits/stdc++.h>
using namespace std;

class node {
public:
	vector<int> edge;
	int visit = 0;
	int mom = 0;
};

void dfs(int k, vector<node>& v) {
	stack<int> stc;
	v[k].visit = 1;
	stc.push(k);

	while (!stc.empty()) {
		int a = stc.top();
		stc.pop();

		for (auto i : v[a].edge) {
			if (v[i].visit == 0) {
				v[i].visit = 1;
				v[i].mom = a;
				stc.push(i);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<node> v(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;

		v[a].edge.push_back(b);
		v[b].edge.push_back(a);
	}

	dfs(1, v);
	for (int i = 2; i <= n; i++) {
		cout << v[i].mom << '\n';
	}
	return 0;
}
