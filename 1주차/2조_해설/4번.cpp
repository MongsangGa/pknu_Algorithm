#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, k, dp[12][12];

int main() {
    fastio;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i; j++) {
            if (!j || i == j) dp[i][j] = 1;
            else dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
    cout << dp[n][k];
    return 0;
}

/*
 * 이항 계수 문제입니다. 다음 문제 해설도 여기서 한번에 하겠습니다.
 * 이항 계수는 팩토리얼을 활용한 공식을 사용하는 방법과 파스칼 삼각형을 사용하는 2가지 방법이 있습니다.
 * 하지만 전자의 경우에는 팩토리얼을 사용하면 값이 커지기 때문에 N 이 커지면 사용하지 못하겠죠.
 * 그래서 파스칼 삼각형으로 구현하는 방법 정도는 기억하고 계셔야 합니다.
 * 이항 계수가 N 개 중에 M 개를 선택하는 문제에서 활용할 수 있기 때문에 코테에서 자주 보일거에요.
 */
