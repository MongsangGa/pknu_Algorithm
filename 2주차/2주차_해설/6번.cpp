#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'003

int t, n, arr[SIZE], ind[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> t;
    while (t--) {
        cin >> n;
        fill(ind, ind + SIZE, 0);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            ++ind[arr[i]];
        }
        for (int i = 1; i <= n; i++)
            if (!ind[i])
                q.push(i);
        int res = 0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            ++res;
            int nxt = arr[now];
            if (--ind[nxt] == 0)
                q.push(nxt);
        }
        cout << res << '\n';
    }
    return 0;
}

