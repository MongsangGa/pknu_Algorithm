#include <bits/stdc++.h>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'003
using namespace std;

vector<int> vec[SIZE], children[SIZE], fir_par;
int n, m, ind[SIZE];
string name[SIZE];
queue<int> q;

int main() {
    fastio;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> name[i];
    }
    sort(name + 1, name + n + 1);

    cin >> m;
    while (m--) {
        string parent, child;
        cin >> parent >> child;
        int p_idx = lower_bound(name + 1, name + n + 1, parent) - name;
        int c_idx = lower_bound(name + 1, name + n + 1, child) - name;
        vec[c_idx].push_back(p_idx);
        ind[p_idx]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : vec[cur]) {
            ind[nxt]--;
            if (ind[nxt] == 0) {
                q.push(nxt);
                children[cur].push_back(nxt);
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << name[i] << ' ' << children[i].size() << ' ';
        for (auto child : children[i]) cout << name[child] << ' ';
        cout << '\n';
    }
    return 0;
}
