#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, arr[303], dp[303];

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    dp[1] = arr[1];
    for (int i = 2; i <= n; i++) dp[i] = max(dp[i - 2], dp[i - 3] + arr[i - 1]) + arr[i];
    cout << dp[n];
    return 0;
}

/*
 * DP 문제를 생각할 때는 점화식을 떠올리기 전에
 * 해당 문제에 자신이 접근하고 있는 과정이
 * 탑다운이 적합할지 바텀업이 적합할지 먼저 생각하는 편입니다
 * 해당 문제는 대다수의 사람들이 바텀업 방식을 선택하겠죠
 *
 * 한번에 한 계단 또는 두 계단씩 오를 수 있고
 * 연속으로 세 개의 계단을 밟을 수 없으니
 * 현재 계단 기준으로
 * 두 계단 이전의 최대값, 세 계단 이전의 최대값 + 한 계단 이전의 값을 더해주는 점화식을 세울 수 있다
 */
