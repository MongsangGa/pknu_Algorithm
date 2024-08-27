#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define SIZE 500

int a, b;
queue <pair<int, int>> que;
int arr[SIZE][SIZE];
bool visit[SIZE][SIZE];
int cnt, area = 0;
int side[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };

void insert() {
    cin >> a >> b;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> arr[i][j];
            visit[i][j] = false;
        }
    }
}

void BFS() {
    cnt = 0;
    area = 0;

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (arr[i][j] == 1 && !visit[i][j])
            {
                cnt++;

                visit[i][j] = true;
                int temp_Area = 1;

                que.push(make_pair(i, j));

                while (!que.empty()) {
                    int y = que.front().first;
                    int x = que.front().second;
                    que.pop();

                    for (int k = 0; k < 4; k++) {
                        int temp_y = y + side[k][0];
                        int temp_x = x + side[k][1];
                        if (temp_x >= 0 && temp_y >= 0 && temp_y < a && temp_x < b && arr[temp_y][temp_x] == 1 && !visit[temp_y][temp_x])
                        {
                            visit[temp_y][temp_x] = true;
                            temp_Area++;
                            que.push(make_pair(temp_y, temp_x));
                        }
                    }
                }
                area = max(area, temp_Area);
            }
        }
    }
}

int main() {
    insert();
    BFS();
    cout << cnt << '\n' << area << '\n';
    return 0;
}