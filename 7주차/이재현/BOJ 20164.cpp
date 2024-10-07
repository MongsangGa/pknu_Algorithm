#include<bits/stdc++.h>
using namespace std;
string s;
int MAX, MIN;

int FindNum(string num) //숫자 찾기 함수 
{
	int cnt = 0;
	int temp = 0;
	cnt = 0;
	for (int i = 0; i < num.length(); i++)
	{
		temp = num[i] - '0';
		if (temp % 2 == 0)continue; //짝수이면 그냥 넘기기 
		cnt++;
	}
	return cnt;
}

string AddNum(string num) // 두자리수일경우 더하기 
{
	int temp = 0;

	for (int i = 0; i < num.length(); i++)
	{
		temp += num[i] - '0';
	}

	return to_string(temp);
}
void Hoseok(string num, int total)
{
	total += FindNum(num);
	if (num.length() == 1)
	{

		MAX = max(MAX, total);
		MIN = min(MIN, total);
		return;
	}
	else if (num.length() == 2)
	{
		string text = AddNum(num);

		Hoseok(text, total);
	}
	else //total 이 3이상일경우 
	{

		for (int i = 1; i < num.length() - 1; i++)
		{
			for (int j = i + 1; j < num.length(); j++)
			{
				string text1 = num.substr(0, i);
				string text2 = num.substr(i, j - i);
				string text3 = num.substr(j, num.length() - j);

				int temp = stoi(text1) + stoi(text2) + stoi(text3);

				Hoseok(to_string(temp), total);
			}
		}
	}
}
void Insert()
{
	MIN = INT_MAX;
	MAX = 0;
	cin >> s;
	Hoseok(s, 0);
	cout << MIN << ' ' << MAX << '\n';


}
int main()
{
	Insert();
	return 0;
}