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
		if (vec.back() < arr[i]) // 벡터 back 이 현재 vector 내에서 제일 큼 
		{
			vec.push_back(arr[i]);
		}
		else
		{
			auto a = lower_bound(vec.begin(), vec.end(), arr[i]); //벡터내에서 arr[i] 와 같거나 큰수 위치 찾기 
			vec[a - vec.begin()] = arr[i];  // 그 위치에 arr[i] 값 대입 10 20 10 -> 10(여기에 arr[2]=10이 대입됨 )  20 ~~~~
		}
	}
	cout << vec.size() << '\n';
}
int main()
{
	BinarySearch();
	return 0;
}