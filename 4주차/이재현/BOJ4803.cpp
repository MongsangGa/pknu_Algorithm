#include<iostream>
#include<vector>
using namespace std;
#define SIZE 501

int a, b, cnt, index;
bool cycle;
vector<int> v[SIZE];
bool visited[SIZE] = { false, };

void DFS(int now, int prev)
{
    visited[now] = true;
    for (int next : v[now])
    {
        if (next == prev) continue;
        if (visited[next])
        {
            cycle = true;
            continue;
        }
        DFS(next, now);
    }
}

void Result()
{
    cnt = 0;

    for (int i = 1; i <= a; i++)
    {
        visited[i] = false;
    }

    for (int i = 1; i <= a; i++)
    {
        if (visited[i]) continue;

        cycle = false;
        DFS(i, -1);

        if (!cycle)
        {
            cnt++;
        }
    }

    cout << "Case " << index << ": ";
    if (cnt == 0)
    {
        cout << "No trees." << '\n';
    }
    else if (cnt == 1)
    {
        cout << "There is one tree." << '\n';
    }
    else
    {
        cout << "A forest of " << cnt << " trees." << '\n';
    }
}

void Insert()
{
    int c, d;
    index = 0;

    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0) break;


        for (int i = 1; i <= a; i++)
        {
            v[i].clear();
        }

        for (int i = 0; i < b; i++)
        {
            cin >> c >> d;
            v[c].push_back(d);
            v[d].push_back(c);
        }
        index++;
        Result();
    }
}

int main()
{
    Insert();
    return 0;
}
