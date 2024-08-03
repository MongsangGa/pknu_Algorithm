#include <iostream>
#include <algorithm>

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'007
using namespace std;

int pArr[SIZE];
void accum(int pArr[], int N) {
	int sum = 0;
	int part_sum = 0;
	for (int i = 0; i < N; ++i) {
		part_sum += pArr[i];
		sum += part_sum;
	}
	cout << sum;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> pArr[i];
	}
	sort(pArr, pArr+N);
	accum(pArr, N);
	return 0;
}