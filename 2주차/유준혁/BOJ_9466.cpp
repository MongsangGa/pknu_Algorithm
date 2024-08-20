#include <iostream>
#include <cstring>
using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'003

int t, n, ans;
int pick[SIZE];
bool vis[SIZE];
bool done[SIZE];

void dfs(int now) {
	vis[now] = true;
	int next = pick[now];
	
	if (!vis[next]) dfs(next); // 방문 X, 다음 노드로 재귀호출
	else if (!done[next]) { // 방문은 되었지만 사이클에 포함되어 있지 않은 경우
		for (int i = next; i != now; i = pick[i]) {
			ans++; // 사이클의 크기 증가
		}
		ans++; // 사이클 시작 노드 포함
	}
	done[now] = true; // 현재 노드를 사이클에 포함
}

int main() {
	cin >> t;
	while(t--) {
		memset(vis, false, sizeof(vis)); //몰랐던 문법 새롭게 알게 됨.
		memset(done, false, sizeof(done)); // 해당 배열을 sizeof 바이트로 false로 모두 초기화. 각 멤버마다 사이클 돌릴 수 있음
		ans = 0;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> pick[i];
		}
		for (int i = 1; i <= n; ++i) {
			if (vis[i]) continue; // 이미 방문했다면 건너뛰기
			dfs(i);
		}
		cout << n - ans << "\n"; // 전체 인원에서 사이클에 해당하는 수(해당되는 인원 수)만큼 빼기
	}
	return 0;
}