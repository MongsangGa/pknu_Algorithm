#include<iostream>
#include<vector>
using namespace std;
#define SIZE 100001
int Dynamic[SIZE];
vector<int>v[SIZE];
bool visited[SIZE];
int N, R, Q, a, b;

void DFS(int child, int parent)
{
	visited[child] = true;
	for (int temp : v[child])
	{
		if (visited[temp])continue;
		DFS(temp, child);
	}
	if (parent != -1)
	{
		Dynamic[parent] += Dynamic[child];
	}
}
void Insert()
{
	cin >> N >> R >> Q;
	for (int i = 1; i <= N; i++)
	{
		Dynamic[i] = 1;
	}
	for (int i = 0; i < N - 1; i++)
	{
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	DFS(R, -1);
	for (int i = 0; i < Q; i++)
	{
		int temp;
		cin >> temp;
		cout << Dynamic[temp] << '\n';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	Insert();
	return 0;
}