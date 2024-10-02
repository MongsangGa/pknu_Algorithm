#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 100'003

int n, m, sn, en, mid, target;
int arr[SIZE];

int main(){
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    cin >> m;
    while (m--) {
        cin >> target;
        sn = 0;
        en = n - 1;
        bool is_find = false;
        while(sn <= en) {
            mid = (sn + en) / 2;
            if (target == arr[mid]) {
                is_find = true;
                break;
            }
            else if (target > arr[mid])
                sn = mid + 1;
            else
                en = mid - 1;
        }
        cout << is_find << '\n';
    }
    return 0;
}
