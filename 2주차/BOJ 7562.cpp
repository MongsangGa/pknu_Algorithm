#include<bits/stdc++.h>
using namespace std;
#define SIZE 301
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
int a, b, start_x, start_y, end_x, end_y;
int dx[] = { 2,-2,2,-2,1,-1,1,-1 };
int dy[] = { 1,-1,-1,1,2,-2,-2,2 };
int arr[SIZE][SIZE];
queue<pair<int, int>>que;

void BFS()
{
	while (!que.empty())
	{
		int x = que.front().first;
		int y = que.front().second;
		que.pop();

		for (int i = 0; i < 8; i++)
		{
			int temp_x = x + dx[i];
			int temp_y = y + dy[i];
			if (temp_x < 0 || temp_x >= b || temp_y < 0 || temp_y >= b || arr[temp_x][temp_y]>0) continue;
			arr[temp_x][temp_y] = arr[x][y] + 1;
			que.push({ temp_x,temp_y });
		}
	}
	cout << arr[end_x][end_y] - 1 << '\n';

}
void CallBFS(int a)
{
	int num = a;
	while (num--)
	{
		cin >> b >> start_x >> start_y >> end_x >> end_y;
		for (int i = 0; i < b; i++)
		{
			for (int j = 0; j < b; j++)
			{
				arr[i][j] = 0;
			}
		}
		que.push({ start_x,start_y });
		arr[start_x][start_y] = 1;
		BFS();
	}
}
int main()
{
	fastio;
	cin >> a;
	CallBFS(a);
	return 0;
}