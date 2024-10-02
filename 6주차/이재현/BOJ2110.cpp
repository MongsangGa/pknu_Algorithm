#include<bits/stdc++.h>
using namespace std;
#define SIZE 200001
int n, m, a, cnt, result;
int wifi[SIZE];
void Count(int mid)
{
	cnt = 1;
	int start = wifi[0];
	for (int i = 0; i < n; i++)
	{
		int end = wifi[i];
		if (end - start >= mid)
		{
			cnt++;
			start = end;
		}
	}
}
void Insert()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> wifi[i];
	}
	sort(wifi, wifi + n);
}
void BinarySearch()
{
	Insert();
	int left = 0; // 첫번째 wifi 설치 위치
	int right = wifi[n - 1] - wifi[0]; // 마지막과 첫번째 wifi 간격
	while (left <= right)
	{

		int middle = (left + right) / 2;
		int start = wifi[0];
		Count(middle);
		if (cnt >= m)
		{
			result = middle;
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