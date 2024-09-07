#include<bits/stdc++.h>
using namespace std;
#define SIZE 1001
int t, n, m, a, b, w;
vector<int>vec[SIZE];
int degree[SIZE]; int Dynamic[SIZE]; int hour[SIZE];
void Reset()
{
	for (int i = 0; i <= n; i++)
	{
		degree[i] = 0;
		Dynamic[i] = 0;
		hour[i] = 0;
		vec[i].clear();
	}
}
void TopologySort()
{
	queue<int>que;

	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			que.push(i);
			Dynamic[i] = hour[i];
		}
	}
	while (!que.empty())
	{
		int temp = que.front();
		que.pop();

		for (int next : vec[temp])
		{
			degree[next]--;
			Dynamic[next] = max(Dynamic[next], Dynamic[temp] + hour[next]);
			if (degree[next] == 0)
			{
				que.push(next);
			}

		}

	}
	cout << Dynamic[w] << '\n';
}
void Insert()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		Reset();
		for (int i = 1; i <= n; i++)
		{
			cin >> hour[i];
		}
		for (int i = 1; i <= m; i++)
		{
			cin >> a >> b;
			vec[a].push_back(b);
			degree[b]++;
		}
		cin >> w;
		TopologySort();
	}

}


int main()
{
	Insert();
	return 0;
}