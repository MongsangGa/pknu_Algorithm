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
		if (binary_search(arr, arr + n, a))
		{
			buffer[i] = 1;
		}
		else
		{
			buffer[i] = 0;
		}
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