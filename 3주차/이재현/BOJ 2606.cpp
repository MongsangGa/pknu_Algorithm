#include<iostream>
#include<vector>
using namespace std;
#define SIZE 101
int a, b, c, d, cnt;
vector<int>vec[SIZE];
bool visit[SIZE] = { false, };
void Insert()
{
	cnt = 0;
	cin >> a >> b;
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d;
		vec[c].push_back(d);
		vec[d].push_back(c);
	}
}

void DFS(int x)
{
	visit[x] = true;
	cnt++;
	for (int i = 0; i < vec[x].size(); i++)
	{
		if (visit[vec[x][i]] == false)
		{
			DFS(vec[x][i]);
		}
	}

}

int main()
{
	Insert();
	DFS(1);
	cout << cnt - 1 << '\n';
}