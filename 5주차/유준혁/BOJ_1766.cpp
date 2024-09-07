#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'003
using namespace std;

vector<int> vec[SIZE], ans;
int n, m, ind[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        ind[b]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " ";
        for (auto nxt : vec[cur]) {
            ind[nxt]--;
            if (ind[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    for (auto a : ans) cout << a << " ";
    return 0;
}
