#include<bits/stdc++.h>
using namespace std;
#define SIZE 1000001
int n;
int arr[SIZE];
vector<int>vec;
void Insert()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
}
void BinarySearch()
{
	Insert();
	vec.push_back(arr[0]);
	for (int i = 0; i < n; i++)
	{
		if (vec.back() < arr[i]) // ���� back �� ���� vector ������ ���� ŭ 
		{
			vec.push_back(arr[i]);
		}
		else
		{
			auto a = lower_bound(vec.begin(), vec.end(), arr[i]); //���ͳ����� arr[i] �� ���ų� ū�� ��ġ ã�� 
			vec[a - vec.begin()] = arr[i];  // �� ��ġ�� arr[i] �� ���� 10 20 10 -> 10(���⿡ arr[2]=10�� ���Ե� )  20 ~~~~
		}
	}
	cout << vec.size() << '\n';
}
int main()
{
	BinarySearch();
	return 0;
}