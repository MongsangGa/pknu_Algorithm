#include <iostream>
#include <queue>

using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 200'003

int n, k, vis[SIZE];
queue<int> q;

int main() {
	cin >> n >> k;
	q.push(n), vis[n] = 1;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		int nextStates[3] = { now * 2, now + 1, now - 1 };
		for (int i = 0; i < 3; ++i) {
			int next = nextStates[i];
			if (next < 0 || next >= SIZE || vis[next] != 0) continue;
			vis[next] = vis[now] + 1;
			q.push(next);
		}
	}
	cout << vis[k] - 1;

	return 0;
}