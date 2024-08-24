#include<bits/stdc++.h>
using namespace std;
#define SIZE 1001
int a, b, day;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int Box[SIZE][SIZE];

queue<pair<int, int>>que;
void Insert()
{
	cin >> a >> b;
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			cin >> Box[i][j];
			if (Box[i][j] == 1)
			{
				que.push({ i,j });

			}
		}
	}
	day = 0;
}
bool Check(int num_y, int num_x)
{
	if (num_y < 0 || num_y >= b || num_x >= a || num_x < 0)
	{
		return false;
	}
	return true;
}
void BFS()
{
	while (!que.empty())
	{
		int y = que.front().first;
		int  x = que.front().second;
		que.pop();
		for (int i = 0; i < 4; i++)
		{
			int temp_y = y + dy[i];
			int temp_x = x + dx[i];
			if (Check(temp_y, temp_x) && Box[temp_y][temp_x] == 0)
			{
				Box[temp_y][temp_x] = Box[y][x] + 1;
				que.push({ temp_y,temp_x });
			}

		}

	}
}
int CheckDay()
{
	for (int i = 0; i < b; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (Box[i][j] == 0)
			{

				return -1;
			}
			if (day < Box[i][j])
			{
				day = Box[i][j];
			}
		}
	}
	return day - 1;

}

int main()
{
	Insert();
	BFS();
	cout << CheckDay() << '\n';


	return 0;
}