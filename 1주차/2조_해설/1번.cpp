#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, changeN, res;

int f(int x) {
    int one = x / 10;
    int two = x % 10;
    return (two * 10) + (one + two) % 10;
}

int main() {
    fastio;
    cin >> n;
    changeN = n;
    while (1) {
        ++res;
        changeN = f(changeN);
        if (n == changeN) break;
    }
    cout << res;
    return 0;
}

/*
 * 다들 이 문제 구현하는 과정을 보니깐 헷갈려서 구현 못하는 경우가 많던데
 * 이럴 때는 변수 명을 헷갈리지 않게 잘 설정하고 함수를 사용해서 로직을 정리하는게 좋습니다
 */
