#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000

int arr[SIZE], n, m;

void Insert() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
}

bool Counting(long long int a) {
    if (a == 0) return false;
    int count = 0;
    for (int i = 0; i < n; i++) {
        count += arr[i] / a;
        if (count >= m)return true;
    }
    return false;
}

void BinarySearch()
{
    long long int left = 1;
    long long int right = arr[n - 1];
    long long int result = 0;
    while (left <= right)
    {
        long long int middle = (left + right) / 2;

        if (Counting(middle)) {
            result = middle;
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    cout << result << '\n';
}

void Solve() {
    Insert();
    BinarySearch();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    Solve();
    return 0;
}
