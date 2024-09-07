#include<bits/stdc++.h>
using namespace std;
#define SIZE 10001
int n, h, a, b, result;
int Dynamic[SIZE]; int degree[SIZE]; int hour[SIZE];
vector<int> vec[SIZE];

void Reset()
{
	for (int i = 1; i <= n; i++)
	{
		Dynamic[i] = 0;
		degree[i] = 0;
		hour[i] = 0;
		vec[i].clear();
	}
}
void Insert()
{
	cin >> n;
	Reset();
	for (int i = 1; i <= n; i++)
	{
		cin >> h >> a;
		hour[i] = h;

		for (int j = 1; j <= a; j++)
		{
			cin >> b;
			vec[b].push_back(i);
			degree[i]++;
		}
	}
}
void TopologySort()
{
	priority_queue<int, vector<int>, greater<int>>que;
	for (int i = 1; i <= n; i++)
	{
		if (degree[i] == 0)
		{
			que.push(i);
			Dynamic[i] = hour[i];
		}
	}
	result = 0;
	while (!que.empty())
	{
		int temp = que.top();
		que.pop();
		result = max(result, Dynamic[temp]);

		for (int next : vec[temp])
		{
			Dynamic[next] = max(Dynamic[next], Dynamic[temp] + hour[next]);
			degree[next]--;
			if (degree[next] == 0)
			{
				que.push(next);
			}
		}
	}

}
void Result()
{
	Insert();
	TopologySort();

	cout << result << '\n';
}
int main()
{
	Result();
	return 0;
}