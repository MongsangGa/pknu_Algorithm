#include<iostream>
#include<queue>
#include<deque>
using namespace std;
queue<int> truck;
deque<pair<int, int>>bridge;

void Insert(int num)
{
	int weight;
	for (int i = 0; i < num; i++)
	{
		cin >> weight;
		truck.push(weight);
	}
}
void Time(int num, int weight, int length)
{
	int result = 0;
	int sum = 0;
	while (true)
	{
		result++;
		for (auto& element : bridge) {
			element.second++;
		}



		if (!bridge.empty() && bridge.front().second == length)
		{
			sum -= bridge.front().first;
			bridge.pop_front();
		}


		if (!truck.empty() && sum + truck.front() <= weight) {
			bridge.push_back({ truck.front(), 0 });
			sum += truck.front();
			truck.pop();
		}


		if (truck.empty() && bridge.empty())
		{
			cout << result << endl;
			break;

		}
	}

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, w, L;
	cin >> n >> w >> L;

	Insert(n);
	Time(n, L, w);

	return 0;
}