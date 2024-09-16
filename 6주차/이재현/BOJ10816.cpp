#include<bits/stdc++.h>
using namespace std;
#define SIZE 500001
int arr[SIZE], n, m, a;
int buffer[SIZE];
void Insert()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> m;
	sort(arr, arr + n);
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		buffer[i] = upper_bound(arr, arr + n, a) - lower_bound(arr, arr + n, a);
	}
	for (int i = 0; i < m; i++)
	{
		cout << buffer[i] << ' ';
	}
}

int main()
{

	Insert();
	return 0;
}