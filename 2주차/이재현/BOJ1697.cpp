#include<bits/stdc++.h>
using namespace std;
#define SIZE 100001
int a, b, result;
int position, timer;
bool visited[SIZE] = { false , };
queue<pair<int, int>>que;
bool CheckState(int num)
{
	if (num < 0 || num>SIZE || visited[num])
	{
		return false;
	}
	return true;
}
void Insert()
{
	cin >> a >> b;
	que.push({ a,0 });
	visited[a] = true;
	result = 0;
}
void BFS()
{
	while (!que.empty())
	{
		position = que.front().first;
		timer = que.front().second;
		que.pop();
		if (position == b)
		{
			result = timer;
			break;
		}
		if (CheckState(position - 1))
		{
			visited[position - 1] = true;
			que.push({ position - 1,timer + 1 });
		}
		if (CheckState(position + 1))
		{
			visited[position + 1] = true;
			que.push({ position + 1,timer + 1 });
		}
		if (CheckState(position * 2))
		{
			visited[position * 2] = true;
			que.push({ position * 2 , timer + 1 });
		}
	}
}
int main()
{
	Insert();
	BFS();
	cout << result << '\n';
	return 0;
}


