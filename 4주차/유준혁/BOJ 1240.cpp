#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'003
using namespace std;

vector<int> vec[SIZE]; // first = 간선과 노드 결합, second = dep
int n, m, my_boss[SIZE], res, dp[SIZE], i, w;


void DFS(int now, int prev) {
    for (auto nxt : vec[now]) {
        if (nxt == prev) continue;
        dp[nxt] += dp[now];
        DFS(nxt, now);
    }
}

int main() {
    fastio;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        //간선 연결 완료
        cin >> my_boss[i];
        if (my_boss[i] != -1) {
            vec[i].push_back(my_boss[i]);
            vec[my_boss[i]].push_back(i);
        }
    }
    fill(dp, dp + SIZE, 0);
    for (int j = 1; j <= m; j++) {
        cin >> i >> w;
        dp[i] += w; // 0 2 4 0 6
    }
    DFS(1, -1);
    for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    return 0;
}
