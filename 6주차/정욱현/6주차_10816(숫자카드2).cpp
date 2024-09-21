#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 500'003

int n, m, target;
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
        int count = 0;
        count = upper_bound(arr, arr + n, target) - lower_bound(arr, arr + n, target);
        cout << count << ' ';
    }
    return 0;
}