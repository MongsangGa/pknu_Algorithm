#include <bits/stdc++.h>
using namespace std;
#define SIZE 100'007

int main(void) {
	int n, k, numerator=1, denominator=1;
	int arr[SIZE];

	scanf("%d %d", &n, &k);
	
	for (int i = 0; i < k; i++) {
		numerator *= (n - i);
		denominator *= (i + 1);
	}

	int result = numerator / denominator;
	printf("%d\n", result);

	return 0;
}