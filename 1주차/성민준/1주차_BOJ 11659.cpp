#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] += v[i - 1];
	}

	int a, b;
	while (m--) {
		cin >> a >> b;
		cout << v[b] - v[a - 1] << '\n';
	}
	return 0;
}
