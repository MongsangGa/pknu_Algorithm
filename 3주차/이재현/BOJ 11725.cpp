#include<iostream>
#include<vector>
using namespace std;
#define SIZE 100001
vector<int> vec[SIZE];
int parent[SIZE] = { 0, };
int n, a, b;
void Insert()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
}
void DFS(int x)
{
	for (int i = 0; i < vec[x].size(); i++)
	{

		if (parent[vec[x][i]] == 0)
		{
			parent[vec[x][i]] = x;
			DFS(vec[x][i]);
		}
	}
}
void Print()
{
	for (int i = 2; i <= n; i++)
	{
		cout << parent[i] << '\n';
	}
}
int main()
{
	Insert();
	DFS(1);
	Print();
	return 0;
}