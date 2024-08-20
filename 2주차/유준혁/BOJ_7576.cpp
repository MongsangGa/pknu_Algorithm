#include <iostream>
#include <queue>
using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'003

int m, n;
int arr[SIZE][SIZE];
int dist[SIZE][SIZE]; // 익는 데 걸리는 일수를 저장
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) {
                q.push({ i, j });
                dist[i][j] = 0; // 익은 토마토의 초기 거리는 0
            }
            else if (arr[i][j] == 0) {
                dist[i][j] = -1; // 아직 익지 않은 토마토는 -1로 초기화
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] >= 0) continue; // 이미 방문했거나 벽(arr=-1, dist = 0)이면 스킵

            dist[nx][ny] = dist[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    int result = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dist[i][j] == -1) {
                cout << -1 << '\n';
                return 0;
            }
            result = max(result, dist[i][j]);
        }
    }

    cout << result << '\n';
    return 0;
}






/*while (!q.empty()) {
	int cu_x = q.front().first;
	int cu_y = q.front().second;
	q.pop();
	for (int i = 0; i < 4; ++i) {
		int nx = cu_x + dx[i];
		int ny = cu_y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || vis[nx][ny] != 0) continue; // 범위를 벗어나거나 방문한 곳이면 큐에 저장 X
		q.push({ nx, ny }), vis[nx][ny] = 1;
	}
} 여러 지점에서 발생하는 경우도 존재. 위 코드는 한 곳에만 익은 토마토가 있을 경우만 해당.
*/