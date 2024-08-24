#include <iostream>
using namespace std;
#define SIZE 100001
int arr[SIZE];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	arr[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int a, b;
	while (m--)
	{
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << '\n';
	}
	return 0;
}