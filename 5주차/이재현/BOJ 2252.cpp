#include<bits/stdc++.h>
using namespace std;
#define SIZE 32001
int n, m, a, b;
vector<int> v[SIZE];
int degree[SIZE];

void Insert()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		degree[b]++;

	}
}
void TopologySort()
{
	Insert();
	queue<int>que;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			que.push(i);
		}
	}
	while (!que.empty())
	{
		int temp = que.front();
		cout << temp << " ";
		que.pop();
		for (int next : v[temp])
		{
			degree[next]--;
			if (degree[next] == 0)
			{
				que.push(next);
			}
		}
	}
}

int main()
{
	TopologySort();
	return 0;
