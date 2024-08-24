#include <bits/stdc++.h>

using namespace std;
#define SIZE 505

int n, m, acnt, cnt;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int arr[SIZE][SIZE];
queue<pair<int, int>> q;

int BFS(int x, int y){
    int c = 1;
    q.push({x, y}), arr[x][y] = 0;
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || arr[nx][ny] == 0)
                continue;
            q.push({nx, ny}), arr[nx][ny] = 0, c++;
        }
    }
    return c;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        scanf("%d", &arr[i][j]);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if(arr[i][j] == 1){
            int ncnt = BFS(i, j);
            cnt = max(cnt, ncnt);
            acnt++;
            }
        }
    }
    printf("%d\n%d",acnt, cnt);
    return 0;
}