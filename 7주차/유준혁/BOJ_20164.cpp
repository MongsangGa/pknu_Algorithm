#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int MIN = 1e9 + 1, MAX = 0;

// 문자열에서 홀수 개수 찾는 함수
int calc_odd(int n)
{
    int cnt = 0;
    while (n)
    {
        if ((n % 10) % 2)
            ++cnt;
        n /= 10;
    }
    return cnt;
}

// 문자열 커팅하면서 분기 관리하는 함수
void DFS(string s, int cnt)
{
    cnt += calc_odd(stoi(s));
    if (s.size() == 1)
    {
        MIN = min(MIN, cnt);
        MAX = max(MAX, cnt);
        return;
    }
    else if (s.size() == 2)
    {
        int part1 = stoi(s.substr(0, 1));
        int part2 = stoi(s.substr(1));
        string ts = to_string(part1 + part2);
        DFS(ts, cnt);
    }
    else
    {
        for (int i = 1; i < s.size(); ++i)
        {
            for (int j = i + 1; j <= s.size(); ++j)
            {
                string part1 = s.substr(0, i);
                string part2 = s.substr(i, j - i);
                string part3 = s.substr(j);
                // int part1, 2, 3로 받아서 자르고 바로 stoi()를 넣으려 하니 자꾸 stoi()에서 타당하지 않은 값이라고 int형으로 못바꿔줌 > 비어있는 지 검사 하고 stoi() 함수 실행
                if (!part1.empty() && !part2.empty() && !part3.empty())
                {
                    int num1 = stoi(part1);
                    int num2 = stoi(part2);
                    int num3 = stoi(part3);

                    string is = to_string(num1 + num2 + num3);
                    DFS(is, cnt);
                }
            }
        }
    }
}

int main()
{
    fastio;
    string n;
    cin >> n;
    DFS(n, 0);
    cout << MIN << ' ' << MAX;
    return 0;
}
