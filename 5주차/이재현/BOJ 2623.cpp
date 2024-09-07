#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define SIZE 1001
int n, m, a, b;
vector<int>vec[SIZE];  vector<int>v;
int degree[SIZE] = { 0, };
vector<int>ans;
void Insert()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			cin >> b;
			v.push_back(b);
		}
		for (int j = 0; j < v.size(); j++)
		{
			for (int k = j + 1; k < v.size(); k++)
			{
				vec[v[j]].push_back(v[k]);
				degree[v[k]]++;
			}
		}
		v.clear();
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
		}
	}
	while (!que.empty())
	{
		if (que.empty())break;

		int temp = que.front();
		que.pop();
		ans.push_back(temp);
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

	if (ans.size() != n)
	{
		cout << 0 << '\n';
		return;
	}

	for (int print : ans)
	{
		cout << print << '\n';
	}
}
int main()
{
	Result();
	return 0;
}