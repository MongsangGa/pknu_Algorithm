#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

int getm(vector<int>& v, int mid) {
	int cnt = 0;
	for (auto i : v) cnt += i / mid;
	return cnt;
}

int main() {
	fastio;
	int n, m, ans = 0;
	cin >> m >> n;
	vector<int> v(n);
	for (int i = 0; i < n; cin >> v[i++]);
	sort(v.begin(), v.end());

	int l = 1, r = 1000000000, mid;
	while (l <= r) {
		mid = (l + r) / 2;
		int k = getm(v, mid);
		if (k < m) r = mid - 1;
		else {
			if (getm(v, mid + 1) < m) {
				ans = mid;
				break;
			}
			l = mid + 1;
		}
	}
	cout << ans;
	return 0;
}
