#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 502

int N, M, board[SIZE][SIZE];
bool visited[SIZE][SIZE];

int dx[4] = { -1, 1, 0 ,0 };
int dy[4] = { 0, 0, -1, 1 };
queue<pair<int, int>> q;
vector<int> arrArea;
int countPicture = 0;
int area = 0;


int bfs(int x, int y) {
	q.push({ x, y });
	visited[x][y] = true;
	int area = 1;
	while (!q.empty()) {
		int cu_x = q.front().first;
		int cu_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = cu_x + dx[i];
			int ny = cu_y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
			if (board[nx][ny] == 1 && visited[nx][ny] == 0) {
				visited[nx][ny] = true;
				area++;
				q.push({ nx, ny });
			}
		}
	}
	return area;
}
bool compare(int i, int j) {
	return i > j;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> board[i][j];

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1 && visited[i][j] == 0) {
				area = bfs(i, j);
				arrArea.push_back(area);
				count++;
				area = 1;
			}
		}
	}
	sort(arrArea.begin(), arrArea.end(), compare);

	cout << count << "\n";
	if (count == 0) cout << '0';
	else    cout << arrArea[0];
	return 0;
}