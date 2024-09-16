#include<bits/stdc++.h>
using namespace std;
#define SIZE 500001
int arr[SIZE];
vector<int>vec;
int n, m, temp, c;

void BinarySearch(int a)
{
	int left = 0;
	int right = n - 1;
	while (left <= right)
	{
		int middle = (left + right) / 2;
		if (arr[middle] > a)
		{
			right = middle - 1;
		}
		else
		{
			if (arr[middle] == a)
			{
				arr[middle] = 0;
			}
			left = middle + 1;
		}
	}

}
void Insert()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < m; i++)
	{
		cin >> c;
		BinarySearch(c);
	}
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == 0)continue;
		vec.push_back(arr[i]);
	}

	cout << vec.size() << '\n';
	for (int next : vec)
	{
		cout << next << ' ';
	}

}
int main()
{
	Insert();
	return 0;

}