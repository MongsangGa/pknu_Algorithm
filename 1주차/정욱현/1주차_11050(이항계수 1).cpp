# include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, k, result;

int fact(int n) { //펙토리얼 구하는 함수
	int result;
	result = 1;   
	for (int i = 1; i <= n; i++)
		result *= i;
	return result;
}
int main () {
	fastio;
	cin >> n;
	cin >> k;
	result = fact(n) / ( fact(k) * fact(n-k) );
	cout << result;
}
