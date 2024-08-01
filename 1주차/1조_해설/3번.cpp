#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1002

int truck[SIZE], curW, curT, sec;
queue<int> q;

int main() {
    fastio;
    int n, l, w;
    cin >> n >> l >> w;
    for (int i = 0; i < n; i++)
        cin >> truck[i];
    for (int i = 0; i < n; i++) {
        while (1) {
            if (q.size() >= l)
                curW -= q.front(), q.pop();
            if (curW + truck[i] <= w)
                break;
            q.push(0);
            ++sec;
        }
        q.push(truck[i]);
        curW += truck[i];
        ++sec;
    }
    cout << sec + l;
    return 0;
}
/*
 * 트럭과 같은 구현 문제 접근하는 방법
 * 1. 문제 직관적으로 바라보기
 * 먼저 출발한 트럭이 먼저 나온다 -> 누가봐도 무조건 큐를 사용한다
 * 이후 나머지 제한사항을 어떻게 큐로 구현할지 생각한다
 * 라는 사고의 흐름으로 이어지는게 가장 효과적입니다.
 */
