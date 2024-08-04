#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define MAX 1000

int main(void) {
    int n, sum=0, total=0;
    int times[MAX];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &times[i]);
    }

    sort(times, times + n);

    for (int i = 0; i < n; i++) {
        sum += times[i];
        total += sum;
    }

    printf("%d\n", total);
    return 0;
}