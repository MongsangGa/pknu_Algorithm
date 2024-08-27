#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, cnt, xCnt, yCnt;
char arr[102][102];

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '.') ++cnt;
            else if (arr[i][j] == 'X') {
                if (cnt >= 2) ++xCnt;
                cnt = 0;
            }
        }
        if (cnt >= 2) ++xCnt;
    }
    for (int i = 0; i < n; i++) {
        cnt = 0;
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == '.') ++cnt;
            else if (arr[j][i] == 'X') {
                if (cnt >= 2) ++yCnt;
                cnt = 0;
            }
        }
        if (cnt >= 2) ++yCnt;
    }
    cout << xCnt << ' ' << yCnt;
    return 0;
}

/*
 * 문제의 규칙에 맞춰서 모두 돌려보면 해결할 수 있습니다.
 * 다음주에 그래프 배우기 전에 이차원 배열에 익숙해지라고 출제했어요.
 */
