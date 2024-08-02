#include <bits/stdc++.h>

using namespace std;


int N[10];

int main () {
    int sum = 0;

for(int i=1; i<10; i++) {
    scanf("%d", &N[i]);
    sum += N[i];
}
	for (int i = 1; i < 10; i++) {
		for (int j = 2; j < 10; j++) {
			if (i == j)
				continue;
			if (sum - (N[i] + N[j]) == 100) {
				N[i] = -1;
				N[j] = -1;
				break;
			}
		}
		if (N[i] == -1)
			break;
	}

	sort(N + 1, N + 10);
	for (int i = 3; i < 10; i++)
		printf("%d\n", N[i]);

    return 0;
}