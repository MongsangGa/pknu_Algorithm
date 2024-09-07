#include<bits/stdc++.h>
using namespace std;
#define SIZE 32001
int n, m, a, b;
vector<int>vec[SIZE];
vector<int>result;
int degree[SIZE] = { 0, };
bool cmp(int a, int b)
{
	return a < b;
}
void Insert()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		degree[b]++;
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
		}
	}
	while (!que.empty())
	{

		int temp = que.top();
		result.push_back(temp);
		que.pop();
		for (int next : vec[temp])
		{
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

	for (int n : result)
	{
		cout << n << ' ';
	}
}
int main()
{
	Result();
	return 0;
}