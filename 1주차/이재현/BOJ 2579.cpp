#include<iostream>
using namespace std;
#define SIZE 301
int stair[SIZE];
int Dynamic[SIZE];

void StepStair(int num)
{
	Dynamic[0] = 0;
	Dynamic[1] = stair[1];
	Dynamic[2] = Dynamic[1] + stair[2];
	for (int i = 3; i <= num; i++)
	{
		Dynamic[i] = max(Dynamic[i - 2], Dynamic[i - 3] + stair[i - 1]) + stair[i];
	}
	cout << Dynamic[num] << endl;
}

int main()
{
	int num;

	cin >> num;
	for (int i = 1; i <= num; i++)
	{
		cin >> stair[i];
	}
	StepStair(num);
	return 0;
}