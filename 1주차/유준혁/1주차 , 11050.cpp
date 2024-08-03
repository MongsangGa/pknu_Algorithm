#include <iostream>
using namespace std;

int N, K;
int fact(int N) {
	if (N <= 1) return 1;
	return fact(N - 1) * N;
}
int main() {
	cin >> N >> K;
	int result = fact(N) / (fact(K) * fact(N - K));
	cout << result;
	return 0;
}