#include <iostream>
#include <vector>
#include <algorithm>

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
using namespace std;

vector<int> arr(9);
int sum = 0;

void f() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			if (sum - arr[i] - arr[j] == 100) {
				arr[i] = arr[j] = -1;
				return;
			}
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	sort(arr.begin(), arr.end());
	f();
	for (int i = 0; i < arr.size();i++) {
		if (arr[i] != -1) {
			cout << arr[i] << " ";
		}
	}
	return 0;
}