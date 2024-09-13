#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> b(m);
	vector<int> ans;
	for (int i = 0; i < n; cin >> a[i++]);
	for (int i = 0; i < m; cin >> b[i++]);
	sort(b.begin(), b.end());

	for (auto i : a) {
		if (!binary_search(b.begin(), b.end(), i)) ans.push_back(i);
	}

	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (auto i : ans) cout << i << " ";

	return 0;
}
