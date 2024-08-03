#include <iostream>

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 100'007
using namespace std;

int arr[SIZE], pnum[SIZE];

int main() {
	fastio;
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++)	cin >> arr[i];
	pnum[0] = arr[0];
	for (int i = 1; i < N; i++)	pnum[i] = pnum[i - 1] + arr[i];

	int i, j;
	for (int k = 0; k < M; k++) {
		cin >> i >> j;
		cout << pnum[j - 1] - pnum[i - 2];
		cout << '\n';
	}
	return 0;
}