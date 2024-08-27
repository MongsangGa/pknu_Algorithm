#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int arr[9], sum;

void f() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == j) continue;
            if (sum - (arr[i] + arr[j]) == 100) {
                arr[i] = arr[j] = -1;
                return;
            }
        }
    }
}

int main() {
    fastio;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    f();
    sort(arr, arr + 9);
    for (int i = 2; i < 9; i++) cout << arr[i] << '\n';
    return 0;
}

/*
 * 이 문제도 부분 합을 이용하면 쉽게 풀 수 있는 문제입니다.
 * 이전 문제와 다르게 제목에 힌트가 없을 때 알고리즘을 떠올릴 수 있는가를 테스트할려고 제출했습니다.
 */
