#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 1003

int n, m, x, y, distance;
int vis[SIZE];
int adj[SIZE][SIZE];

int DFS(int x, int y) {
    //???
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i; i < n - 1; i++) {
        cin >> x >> y >> distance;
        adj[x][y] = distance;
		adj[y][x] = distance;
    }
    for(int i = 0; i < m; i++) {
        cin >> x >> y;
        cout << DFS(x, y);
    }
    return 0;
}
