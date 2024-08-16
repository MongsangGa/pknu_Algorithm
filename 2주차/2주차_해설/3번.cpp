#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 200'002

int n, k, vis[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> n >> k;
    q.push(n), vis[n] = 1;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (auto nxt: {now * 2, now + 1, now - 1}) {
            if (nxt < 0 || nxt >= SIZE || vis[nxt]) continue;
            vis[nxt] = vis[now] + 1;
            q.push(nxt);
        }
    }
    cout << vis[k] - 1;
    return 0;
}

