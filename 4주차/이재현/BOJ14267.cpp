#include<bits/stdc++.h>
#define SIZE 100001
using namespace std;

int n, m, q, w;
vector<int> v[SIZE];
int praise[SIZE];
bool visited[SIZE];

void DFS(int now)
{
    visited[now] = true;
    for (int a : v[now])
    {
        if (visited[a]) continue;
        praise[a] += praise[now];
        DFS(a);
    }
}

void Insert()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        visited[i] = false;
        praise[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (num == -1) continue;
        v[num].push_back(i);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> q >> w;
        praise[q] += w;
    }
}

void Result()
{
    Insert();
    DFS(1);
    for (int i = 1; i <= n; i++)
    {
        cout << praise[i] << ' ';
    }
    cout << '\n';
}

int main() {
    Result();
    return 0;
}
