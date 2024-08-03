#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int n, share, remainder, nextS, nextR, cycle = 0, result = 0, temp;
	scanf("%d", &n);
	temp = n;

	if (n == 0) {
		printf("1");
		return 0;
	}

	while (result != n) {
		if (temp < 10) {
			result = temp * 10 + temp;
		}
		else {
			share = temp / 10;
			remainder = temp % 10;

			nextS = remainder * 10;
			nextR = (share + remainder) % 10;

			result = nextR + nextS;
		}
		temp = result;
		cycle++;
	}
	printf("%d", cycle);
	return 0;
}