#include <iostream>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

// 배열 선언할 때 arr[100'000'003]처럼 보기 쉽게 작은 따옴표 넣을 수 있음

int arr[100'003], psum[100'003]; // 배열같이 값이 큰 것들은 메인 안에 선언하지 말기, 배열 범위 주어진 값보다 3정도 더 여유주기
int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)// 배열 받기 문법
        cin >> arr[i];

    int a, b;
    psum[0] = arr[0];
    for (int i = 1; i < n; i++) {
        psum[i] = psum[i - 1] + arr[i];
    }
    for (int i = 0; i < m; i++) {//for문 한줄짜리는 괄호 생략하기 
        cin >> a >> b;
        cout << psum[b - 1] - psum[a - 2] << '\n';
    }//cout 줄바꿈은 endl이 아니라 \n으로 쓰기 
}