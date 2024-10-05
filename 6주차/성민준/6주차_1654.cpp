#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)

int getm(vector<int>& v, int mid) {
	int sum = 0;
	for (auto i : v) sum += i / mid;
	return sum;
}

int main() {
	fastio;
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; cin >> v[i++]);

	int l = 0, r = INT_MAX, mid;
	while (l <= r) {
		mid = l + (r - l) / 2;
		int k = getm(v, mid);
		if (k < m) r = mid - 1;
		else {
			if (getm(v, mid + 1) < m) break;
			l = mid + 1;
		}
	}
	cout << mid;
	return 0;
}
