#include<bits/stdc++.h>
using namespace std;
#define SIZE 501
int n, m;

int path[SIZE][SIZE];
int Dynamic[SIZE][SIZE];
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
void Insert()
{

	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> path[i][j];
			Dynamic[i][j] = -1;
		}
	}
}
int DFS(int x, int y)
{
	if (x == n - 1 && y == m - 1)
	{
		return 1;
	}
	if (Dynamic[y][x] != -1)
	{
		return Dynamic[y][x];
	}
	Dynamic[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int temp_x = x + dx[i];
		int temp_y = y + dy[i];
		if (temp_x < 0 || temp_x >= n || temp_y < 0 || temp_y >= m)continue;
		if (path[temp_y][temp_x] < path[y][x])
		{
			Dynamic[y][x] = Dynamic[y][x] + DFS(temp_x, temp_y);
		}
	}
	return Dynamic[y][x];

}
int main()
{
	Insert();

	cout << DFS(0, 0) << '\n';
	return 0;
}