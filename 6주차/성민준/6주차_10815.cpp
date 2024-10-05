#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

int main() {
	fastio;
	int n, m;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; cin >> v[i++]);
	sort(v.begin(), v.end());
	cin >> m;
	while (m--) {
		cin >> n;
		cout << binary_search(v.begin(), v.end(), n) << " ";
	}
	return 0;
}
