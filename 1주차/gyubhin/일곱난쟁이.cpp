#include <bits/stdc++.h>
using namespace std;
#define SIZE 9

int main(void) {
	int arr[SIZE];
	int sum=0, num1=-0, num2=0;

	for (int i = 0; i < SIZE; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (sum - (arr[i] + arr[j]) == 100) {
				num1 = i;
				num2 = j;
				break;
			}
		}
		if (num1 != 0)
			break;
	}

	arr[num1] = arr[num2] = 0;
	sort(arr, arr + 9);
	for (int i = 2; i < SIZE; i++) {
		printf("%d\n", arr[i]);
	}
	return 0;
}