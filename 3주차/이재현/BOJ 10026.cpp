#include<iostream>
#include<cstring>
using namespace std;
#define SIZE 101
int n, cnt;
char color[SIZE][SIZE];
bool visit[SIZE][SIZE] = { false, };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void Insert()
{
	cin >> n;
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> color[i][j];
		}
	}

}
void Blind()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (color[i][j] == 'G')
			{
				color[i][j] = 'R';
			}
		}
	}
}

void DFS(int x, int y)
{
	if (visit[y][x] == true) return;
	visit[y][x] = true;
	for (int i = 0; i < 4; i++)
	{
		int temp_x = x + dx[i];
		int temp_y = y + dy[i];
		if (temp_x < 0 || temp_x >= n || temp_y < 0 || temp_y >= n)continue;
		if (color[temp_y][temp_x] == color[y][x] && visit[temp_y][temp_x] == false)
		{
			DFS(temp_x, temp_y);
		}
	}
}
void ResetMemory()
{
	cnt = 0;
	memset(visit, false, sizeof(visit));
}
void Print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == false)
			{
				DFS(j, i);
				cnt++;
			}
		}
	}
	cout << cnt << ' ';
	ResetMemory();
	Blind();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (visit[i][j] == false)
			{
				DFS(j, i);
				cnt++;
			}
		}
	}
	cout << cnt;
}
int main()
{
	Insert();
	Print();
	return 0;
}
