#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'000'003
using namespace std;

vector<int> vec[SIZE];
int n, m, vis[SIZE], res, dp[SIZE][2];


// 얼리어답터가 주어지지 않음. 본인이 얼답일때, 아닐때로 나뉨
// 최소 얼리어 답터 수 : dp 최소값으로 해야함. => min()
// 전에 배운 dp배열 활용 > SIZE만큼의 dp가 2가지의 경우로 나뉨. dp[SIZE][2];
// dp[SIZE][0] = 본인이 얼리어답터일 때
// dp[SIZE][1] = 본인이 얼리어답터가 아닐때
void DFS(int now, int prev) {
    vis[now] = 1;
    dp[now][0] = 0;
    dp[now][1] = 1;
    for (auto nxt : vec[now]) {
        if (nxt == prev) continue;
        if (vis[nxt] == 1) continue;
        DFS(nxt, now);

        dp[now][0] += dp[nxt][1]; // 현재 본인이 얼리어답터 X -> 다음(자식) 밑 주변 노드는 얼리어답터여야함. 루트까지 간단 생각으로 코드짜기
        dp[now][1] += min(dp[nxt][0], dp[nxt][1]); // 현재 본인이 얼리어답터라면 주변노드는 얼리일 수도 있고, 아닐 수도 있음. 그중 최소값을 구하는 문제
        //결국 마지막에 계산하는 dp[value][0]과 dp[value][1]에 마지막 노드(루트)가 얼답일때 아닐때, 즉 모든 경우가 상정된 값들의 합으로 이루어짐
    }
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    //1을 루트로 잡고 재귀를 통해 1이 가장 마지막에 계산됨. 따라서 답 출력때도 dp[1]값을 출력하면 됨.
    DFS(1, -1);
    cout << min(dp[1][0], dp[1][1]);
    return 0;
}
