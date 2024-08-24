#include<iostream>
#include<vector>
using namespace std;
int cnt, n, m, a, b, num1, num2;
#define SIZE 101
vector<int>vec[SIZE];
bool visit[SIZE];
void Insert()
{
	cnt = -1;
	cin >> n >> num1 >> num2;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
}
void DFS(int start, int end, int num)
{
	visit[start] = true;
	if (start == end)
	{
		cnt = num;
	}
	for (int i = 0; i < vec[start].size(); i++)
	{
		if (visit[vec[start][i]] == false)
		{
			DFS(vec[start][i], end, num + 1);
		}
	}
}
void Print()
{
	cout << cnt << '\n';
}
int main()
{
	Insert();
	DFS(num1, num2, 0);
	Print();
	return 0;
}