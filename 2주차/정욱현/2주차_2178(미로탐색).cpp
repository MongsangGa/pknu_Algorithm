#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 103

int n, m, visit[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1}; // xy 상하좌우 검색하기 위한 값들 모아노은 배열  
char arr[SIZE][SIZE];
queue<pair<int, int> > q; // int2개씩 묶은 데이터 구조로 큐에 저장  

int main(){
	fastio;
	cin >> n >> m; // 미로입력받음 
	for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];
	
	q.push({0, 0}); // 큐에 출발지점 넣고 시작 
	visit[0][0] = 1;
	while (!q.empty()){
		auto [x, y] = q.front(); // 상하좌우 검색할 위치 x, y값 큐에서 꺼내기  
		q.pop();
		for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == '0' || visit[nx][ny] <= visit[x][y] + 1) continue;
            // 위 조건시 큐에 넣치 않는다 visit[][]조건은 이미 갔다온 곳을 구분해서 갔다온 곳은 큐에 넣지 않도록 한다  
            q.push({nx, ny}), visit[nx][ny] = visit[x][y] + 1; // 위 조건을 만족하면 큐에 넣는다  
        }
	} 
	
	cout << visit[n][m];
return 0;
}

