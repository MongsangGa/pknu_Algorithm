#include<bits/stdc++.h>
using namespace std;
int a, b;
int max_index;
long long int result;
#define SIZE 1000001
int arr[SIZE];
void Insert(int num)
{
	for (int i = 1; i <= num; i++)
	{
		cin >> arr[i];
	}

}
void Stock(int num)
{
	while (num--)
	{
		cin >> b;
		Insert(b);
		result = 0;
		max_index = 0;
		for (int i = b; i >= 1; i--)
		{
			if (arr[i] > max_index)
			{
				max_index = arr[i];
			}
			else
			{
				result += max_index - arr[i];
			}
		}
		cout << result << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a;
	Stock(a);
	return 0;
}