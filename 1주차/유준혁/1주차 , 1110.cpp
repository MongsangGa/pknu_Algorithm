#include <iostream>

#define fastio cin.tie(0), ios base::sync_with_stdio(0)
using namespace std;
int N, orgN, A, afN, preN;

int main() {
	cin >> N;
	orgN = N;
	int length = 1;
	while (true) {
		preN = N % 10;
		A = N / 10 + N % 10;
		N = preN * 10 + A % 10;
		if (N == orgN) {
			cout << length;
			break;
		}
		length++;
	}
	return 0;
}