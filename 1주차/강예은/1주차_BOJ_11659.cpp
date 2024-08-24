#include <bits/stdc++.h>

using namespace std;

int main () {
    int N, M, i, j;
    int num[100001];
    int sum[100001];
    scanf("%d %d", &N, &M);

	for (int k = 1; k < N + 1; k++)
	{
		scanf("%d", &num[k]);
		sum[k] = sum[k - 1] + num[k];
	}

	for (int k = 1; k < M + 1; k++)
	{
		scanf("%d %d", &i, &j);
		printf("%d\n", sum[j] - sum[i - 1]);
	}
    return 0;
}