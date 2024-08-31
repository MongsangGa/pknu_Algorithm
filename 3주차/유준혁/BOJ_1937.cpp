#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 503
using namespace std;

int n, m, dp[SIZE][SIZE], grid[SIZE][SIZE];
int res = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int DFS(int x, int y) {
    //dp배열이란 예를들어 판다가 0,0에서 움직일 때, 갈 수 있는 경로의 수를 저장하고있는 배열이다.
    //따라서, 어느곳에서 시작하든 일단 dp 배열 인덱스에 값이 -1이 아닌 다른값이라면 그 값이, 갈 수 있는 최대 경로의 수를 이미 저장하고있는 상태
    //만약 dp[0][0] 값이 3이라면 dp[1][0]에서 dp[0][0]으로 간다하면 그 뒤로는 계산 할 필요가 없다는 뜻
    //dp[x][y] 값이 비어있지 않으므로 해당 인덱스 값을 바로 반환 후 > +1해서 dp[1][0]에 저장
    //아니 근데 왜 안됨
    if (dp[x][y] != -1) return dp[x][y];
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx > n || ny < 1 || ny > n)
            continue;
        if (grid[x][y] < grid[nx][ny])
            dp[x][y] = DFS(nx, ny) + 1;
    }

    return dp[x][y];
}

int main() {
    fastio;
    cin >> n;

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // (1,1)부터 (n,n)까지 dfs 실시. dp배열 이용해서 이미 저장되어있는 값 활용해서 모든 자리에서 시작하는 경우 계산
            res = max(res, DFS(i, j));
            // 결국 dp배열의 가장 큰 값을 찾으면 되는것이 아닌가
            // 왜 0이 나오는지,,
        }
    }
    cout << res;

    return 0;
}