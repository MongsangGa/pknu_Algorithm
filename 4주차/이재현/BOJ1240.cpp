#include<iostream>
#include<vector>
using namespace std;
#define SIZE 1001
int N, M, v1, v2, e, dist;
vector<int> v[SIZE];
bool visited[SIZE];
int edge[SIZE][SIZE] = { 0, };
bool found;

void DFS(int now, int end)
{

    visited[now] = true;

    if (now == end)
    {
        found = true;
        return;
    }

    for (int a : v[now])
    {
        if (visited[a]) continue;

        dist += edge[now][a];
        DFS(a, end);

        if (found) return;
        dist -= edge[now][a];
    }
}

void Reset()
{
    for (int i = 1; i <= N; i++)
    {
        visited[i] = false;
    }
    found = false;
    dist = 0;
}

void Insert() {
    cin >> N >> M;

    for (int i = 0; i < N - 1; i++)
    {
        cin >> v1 >> v2 >> e;
        edge[v1][v2] = e;
        edge[v2][v1] = e;
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    for (int i = 0; i < M; i++)
    {
        Reset();
        int x, y;
        cin >> x >> y;
        DFS(x, y);
        cout << dist << '\n';
    }
}

int main()
{
    Insert();
    return 0;
}
