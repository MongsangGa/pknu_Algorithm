#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

class node {
public:
	vector<int> edge;
	int visit = 0;
};

void dfs(int k, vector<node>& v) {
	stack<int> stc;
	v[k].visit = 1;
	stc.push(k);

	while (!stc.empty()) {
		int a = stc.top();
		stc.pop();

		for(auto i:v[a].edge){
			if (v[i].visit == 0) {
				v[i].visit = 1;
				cnt++;
				stc.push(i);
			}
		}
	}

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<node> v(n + 1);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v[a].edge.push_back(b);
		v[b].edge.push_back(a);
	}

	dfs(1, v);
	cout << cnt;
	return 0;
}
