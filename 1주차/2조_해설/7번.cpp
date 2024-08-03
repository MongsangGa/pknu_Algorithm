#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, arr[1002], res;

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < n; i++) arr[i + 1] += arr[i];
    for (int i = 0; i < n; i++) res += arr[i];
    cout << res;
    return 0;
}

/*
 * 이 문제도 구간 합을 활용하는 문제인데 문제의 설명부터 초반 구간 합이 커지면 시간이 늘어나는 것을 친절하게 설명하고 있죠.
 * 3문제 째이기 때문에 이제는 알아챌 수 있어야 합니다.
 */
