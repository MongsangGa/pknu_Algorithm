#include <bits/stdc++.h>
using namespace std;

#define SIZE 102

int n, visited[SIZE][SIZE], dx[]={-1,0,1,0}, dy[]={0,-1,0,1};
vector<vector<char>> arr;
queue<pair<int, int>> q;

void check(int a, int b, bool blind) {
    char color = arr[a][b];
    q.push({a, b});
    visited[a][b] = 1;

    while (!q.empty()) {
        auto pos = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int NewX = pos.first + dx[i];
            int NewY = pos.second + dy[i];

            if (NewX >= n || NewX < 0 || NewY >= n || NewY < 0 || visited[NewX][NewY]) continue;

            if (blind) {
                // r == g
                if ((color == 'R' || color == 'G') && (arr[NewX][NewY] == 'R' || arr[NewX][NewY] == 'G')) {
                    q.push({NewX, NewY});
                    visited[NewX][NewY] = 1;
                } else if (color == arr[NewX][NewY]) {
                    q.push({NewX, NewY});
                    visited[NewX][NewY] = 1;
                }
            } else {
                // r, g, b
                if (color == arr[NewX][NewY]) {
                    q.push({NewX, NewY});
                    visited[NewX][NewY] = 1;
                }
            }
        }
    }
}

int countArea(bool blind) {
    memset(visited, 0, sizeof(visited));    //초기화
    int cnt = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                check(i, j, blind);
                cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    scanf("%d", &n);
    arr.resize(n, vector<char>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    int not_blind = countArea(false);
    int blind = countArea(true);

    printf("%d %d\n", not_blind, blind);

    return 0;
}
