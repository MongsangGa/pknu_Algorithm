#include<bits/stdc++.h>
using namespace std;
#define SIZE 1001
#define DIVIDE 10007
int a, b;
int Dynamic[SIZE][SIZE];

inline void Reset(int a)
{
	for (int i = 1; i <= a; i++)
	{
		Dynamic[i][0] = 1;
		Dynamic[i][i] = 1;
	}
}
void DIV(int a, int b)
{
	Reset(a);
	for (int i = 1; i <= a; i++)
	{
		for (int j = 1; j < i; j++)
		{
			Dynamic[i][j] = (Dynamic[i - 1][j - 1] % DIVIDE + Dynamic[i - 1][j] % DIVIDE) % DIVIDE;
		}
	}
	cout << Dynamic[a][b] << '\n';
}

int main()
{
	cin >> a >> b;
	DIV(a, b);

	return 0;
}