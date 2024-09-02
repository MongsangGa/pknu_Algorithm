#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'003
using namespace std;

vector<int> vec[SIZE]; // first = 간선과 노드 결합, second = dep
int n, m, compo, vis[SIZE], res, cnt;
bool isCycle[SIZE];

// 결국 시냅스(트리)의 개수 - 1 이 res 값이 되지 않을까.
// 시냅스가 2개 일 때 > res = 1
// 시냅스가 3개 일 때 > res = 2
// 시냅스가 4개 일 때 > res = 3
// > 예외 사이클이 존재할 수도 있음
// 사이클 1개 발생 > 1번 작업 | 2개 발생 > 2번 작업
// 사이클의 개수 + 이어져 있지 않는 노드(4, 5, 6)의 개수 더하면 값이 될 것.
// 사이클의 수가 정상적 값이 나오지 않음.
// 정상적으로 나오는데 왜틀렸지
// 사이클 개수를 배열로 만들기.
void DFS(int now, int prev) {
    vis[now] = 1;
    for (auto nxt : vec[now]) {
        if (!vis[nxt]) DFS(nxt, now); // 나(부모노드)에서 방문한 적이 없음. == 트리이다.
        // 방문한 적이 있으며 바로 전 노드 값이 아닐 때 = 사이클이다. + 처음 사이클로 발견 한 경우
        else if (!isCycle[nxt] && nxt != prev) cnt += 1;
    }
    isCycle[now] = true;
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            DFS(i, -1);
            res += 1;
        }
    }
    cout << res - 1 + cnt;
    return 0;
}
