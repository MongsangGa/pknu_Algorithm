#include<bits/stdc++.h>
using namespace std;
#define SIZE 10001
long long int arr[SIZE];
long long int num, cnt;

inline void Insert()
{
	cin >> num >> cnt;
	for (int i = 0; i < num; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + num);
}
void binarySearch()
{
	long long int left = 1;
	long long int right = arr[num - 1];
	while (left <= right)
	{
		long long int mid = (left + right) / 2;
		long long int count = 0;
		for (int i = 0; i < num; i++)
		{
			count += arr[i] / mid;
		}
		if (count < cnt)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	cout << right << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Insert();
	binarySearch();

	return 0;
}