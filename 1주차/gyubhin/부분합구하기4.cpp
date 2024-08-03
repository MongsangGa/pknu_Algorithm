#include <bits/stdc++.h>
using namespace std;
#define SIZE 100'007

int main(void) {
	int n, m, start, end, result;
	int arr[SIZE], psum[SIZE];

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}

	psum[1] = arr[1];
	for (int i = 1; i <= n; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &start, &end);
		result = psum[end] - psum[start - 1];
		printf("%d\n", result);
	}
	return 0;
}