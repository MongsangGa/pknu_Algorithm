#include<bits/stdc++.h>
using namespace std;

#define SIZE 41
int a, b;
int Dynamic[SIZE];
int VIP[SIZE];

void Insert() {
    cin >> a >> b;
    for (int i = 1; i <= b; i++)
    {
        cin >> VIP[i];
    }
}

void Result()
{
    Insert();


    Dynamic[0] = 1;
    Dynamic[1] = 1;
    if (a > 1) {
        Dynamic[2] = 2;
    }
    for (int i = 3; i <= a; i++)
    {
        Dynamic[i] = Dynamic[i - 1] + Dynamic[i - 2];
    }

    long long int answer = 1;
    int prev = 0;

    for (int i = 1; i <= b; i++)
    {
        answer *= Dynamic[VIP[i] - prev - 1];
        prev = VIP[i];
    }


    answer *= Dynamic[a - prev];
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    Result();
    return 0;
}