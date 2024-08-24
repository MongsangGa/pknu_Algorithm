#include <bits/stdc++.h>
using namespace std;

bool inrange(int n) { return 0 <= n && n <= 100000; }

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(100001);
	queue<int> qu;

	qu.push(n);
	v[n] = 1;

	while (!qu.empty()) {
		int cur = qu.front();
		qu.pop();
		int s[3] = { cur - 1,cur + 1,cur * 2 };

		if (cur == k) {
			cout << v[k] - 1;
			break;
		}

		for (auto i : s) {
			if (inrange(i) && v[i] == 0) {
				v[i] = v[cur] + 1;
				qu.push(i);
			}
		}
	}
	return 0;
}
