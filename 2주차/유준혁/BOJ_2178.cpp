#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 103	

int N, M;
char board[SIZE][SIZE];
int dist[SIZE][SIZE];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int, int>> q;

int bfs(int x, int y) {
	q.push({ x, y });
	dist[x][y] = 1;
	while (!q.empty()) {
		int cu_x = q.front().first;
		int cu_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cu_x + dx[i];
			int ny = cu_y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && board[nx][ny] == '1' && dist[nx][ny] == 0) {
				dist[nx][ny] = dist[cu_x][cu_y] + 1;
				q.push({ nx, ny });
			}
		}
	}
	return dist[N-1][M-1];
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];
	int minCount= bfs(0, 0);
	cout << minCount;

	return 0;
}