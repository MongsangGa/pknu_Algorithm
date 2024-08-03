#include <iostream>
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)
#define SIZE 1'007
using namespace std;

char room[SIZE][SIZE];

int main() {
	int N;
	char K;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> K;
			if (K == '.') room[i][j] = 1;
			else room[i][j] = 0;
		}
	}
	int row_count = 0;
	int row = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (room[i][j] == 1) ++row_count;
			else row_count = 0;
			if (row_count == 2) ++row;
		}
		row_count = 0;
	}
	int col_count = 0;
	int col = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (room[j][i] == 1) ++col_count;
			else col_count = 0;
			if (col_count == 2) ++col;
		}
		col_count = 0;
	}
	cout << row << " " << col;
	return 0;
}