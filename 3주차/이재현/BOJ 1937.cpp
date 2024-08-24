#include<bits/stdc++.h>
using namespace std;
#define SIZE  501
int a, answer;
int dx[] = { 1,-1,0,0 }; int dy[] = { 0,0,1,-1 };
int Dynamic[SIZE][SIZE]; int panda[SIZE][SIZE];

void Insert()
{
	cin >> a;
	answer = 0;
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cin >> panda[i][j];
			Dynamic[i][j] = -1;
		}
	}
}
int DFS(int x, int y)
{
	if (Dynamic[y][x] != -1)return Dynamic[y][x];
	Dynamic[y][x] = 0;
	for (int i = 0; i < 4; i++)
	{
		int  temp_x = x + dx[i];
		int temp_y = y + dy[i];
		if (temp_x < 0 || temp_x >= a || temp_y < 0 || temp_y >= a)continue;
		if (panda[y][x] < panda[temp_y][temp_x])
		{
			Dynamic[y][x] = max(Dynamic[y][x], DFS(temp_x, temp_y) + 1);
		}
	}
	return Dynamic[y][x];
}
void Result()
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			answer = max(answer, DFS(i, j));
		}
	}
	cout << answer + 1 << '\n';
}
int main()
{
	Insert();
	Result();

	return 0;
}