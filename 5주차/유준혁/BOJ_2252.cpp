#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 32'010
using namespace std;

vector<int> vec[SIZE], res;
int n, m, ind[SIZE], k;
queue<int> q;

int main() {
    fastio;
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        ind[y]++;
    }
    for (int i = 1; i <= n; i++) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }
    k = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (auto nxt : vec[cur]) {
            ind[nxt]--;
            if (ind[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    for (auto re : res) cout << re << ' ';
    return 0;
}
