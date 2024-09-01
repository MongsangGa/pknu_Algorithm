#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 1003

int n, m, boss, employee, w;
int vis[SIZE];
int wEmployee[SIZE];
vector<int> adj[SIZE];

int DFS(int employee, int w) {
    wEmployee[employee] += w;
    if (adj[employee] = {}) return 0;
    else DFS() // 재귀로 칭찬받는 사람들의 w수치를 모두 올리게 만들고 싶은데 못만들겠다


}
int main(){
    fastio;
    cin >> n >> m;

    for(int i = 1; i < n + 1; i++) {
        cin >> boss;
        adj[i].push_back(boss);
    }

    for (int i = 0; i < m; i++) {
        cin >> employee >> w;
        DFS(employee, w);
    }

    cout << wEmployee;

    return 0;
}
