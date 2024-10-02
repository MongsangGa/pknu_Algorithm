#include<bits/stdc++.h>
using namespace std;

#define SIZE 10001
int n, cnt;
long long int result;
int arr[SIZE];

void Insert()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	result = 0;
}
void Result()
{
	Insert();
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			temp = arr[i] + arr[j];

			auto a = upper_bound(arr + j + 1, arr + n, -temp);
			auto b = lower_bound(arr + j + 1, arr + n, -temp);
			result += (a - b);
		}
	}
	cout << result << '\n';
}
int main()
{
	Result();
	return 0;
}