#include<bits/stdc++.h>
using namespace std;
#define SIZE 101
int n, m, x, y, k;
struct Node
{
	int num;  //부품 번호
	int cnt; // 필요 개수 
};
vector<Node> vec[SIZE];
int degree[SIZE]; int Dynamic[SIZE];

void Reset()
{
	for (int i = 1; i <= n; i++)
	{
		vec[i].clear();
		degree[i] = 0;
		Dynamic[i] = 0;
	}
}

void Insert()
{
	cin >> n >> m;
	Reset();
	for (int i = 1; i <= m; i++)
	{
		cin >> x >> y >> k;
		vec[x].push_back({ y,k });
		degree[y]++;
	}
}

void TopologySort()
{
	queue<int>que;
	que.push(n);

	Dynamic[n] = 1;

	while (!que.empty())
	{
		int temp = que.front();
		que.pop();
		for (Node next : vec[temp])
		{
			int x = next.num;
			int y = next.cnt;

			Dynamic[x] += Dynamic[temp] * y;
			degree[x]--;
			if (degree[x] == 0)
			{
				que.push(x);
			}
		}
	}
}
void Result()
{
	Insert();
	TopologySort();
	for (int i = 1; i <= n; i++)
	{
		if (vec[i].size() == 0)
		{
			cout << i << " " << Dynamic[i] << '\n';
		}
	}
}
int main()
{
	Result();
	return 0;
}