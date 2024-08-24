#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> que;

int a, b;
int result[101][101];
char arr[101][101];
int visited[101][101];
void insert()
{
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        cin >> arr[i];
    }
}
void BFS(int start_x, int start_y)
{
    visited[start_x][start_y] = 1;

    que.push({ start_x,start_y });

    while (!que.empty())
    {
        int x = que.front().first;
        int y = que.front().second;

        que.pop();

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x >= 0 && next_x < a && next_y >= 0 && next_y < b)
            {
                if (arr[next_x][next_y] == '1' && visited[next_x][next_y] == 0) {
                    result[next_x][next_y] = result[x][y] + 1;

                    visited[next_x][next_y] = 1;

                    que.push({ next_x,next_y });

                }
            }
        }

    }
    cout << result[a - 1][b - 1] + 1 << '\n';
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    insert();
    BFS(0, 0);

    return 0;
}