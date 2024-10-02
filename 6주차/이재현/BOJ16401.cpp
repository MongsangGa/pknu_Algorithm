#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000001
int n, m; int result = 0;
int cookie[SIZE];
void Insert()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> cookie[i];
	}
	sort(cookie, cookie + m);
}
bool Length(int mid)
{
	if (mid == 0)return false;
	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		cnt += cookie[i] / mid;
		if (cnt >= n)return true;
	}

	return false;
}
void BinarySearch()
{
	Insert();
	int left = 1;
	int right = cookie[m - 1];
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (Length(middle))
		{
			if (result < middle)
			{
				result = middle;
			}
			left = middle + 1;
		}
		else
		{
			right = middle - 1;
		}
	}
	cout << result << '\n';
}

int main()
{
	BinarySearch();
	return 0;
}