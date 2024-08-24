#include <stdio.h>

int fact(int a) {
    int r = 1;
    for (int i = 1; i <= a; i++) r *= i;
    return r;
}
int main() {
    int k, n;
    scanf("%d %d", &n, &k);
    printf("%d", fact(n) / (fact(k) * fact(n - k)));
    return 0;
}
