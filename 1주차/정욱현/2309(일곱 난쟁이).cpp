#include <bits/stdc++.h> //c++ 표준라이브러리 쓸수 있는 해더
using namespace std; // 표준라이브러리 함수 함수명만으로 사용하게끔 설정 
#define fastio cin.tie(0), ios_base::sync_with_stdio(0) // 입출력 속도향상 

int arr[9];
int sum;

void f(){ // 가짜 난쟁이를 찾는 함수  
	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			if (i==j) continue;
			if (sum - (arr[i] + arr[j]) == 100){
				arr[i] = arr[j] = -1; // 난쟁이의 키는 양수이므로 가짜 난쟁이들을 -1로 설정하고 정렬하면 2~8번 인덱스가 진짜 난쟁이 
				return;
			}
		}
	}
}
int main(){
	sum = 0;
	stdio;
	for(int i =0; i < 9; i++){
		cin >> arr[i]; // 원래는 std::cin C++의 경우 입출력에 타입 형식지정 필요없음 
		sum += arr[i];
	}
	f();
	sort(arr, arr + 9); // 원래는 std::sort() 배열의 시작과 끝을 정해주고 정렬시키는 함수 
	for (int i = 2; i < 9; i++) cout << arr[i] << '\n'; // << 스트림 삽입 서로다른 타입 데이터 <<로 합침 
	return 0;
}
 
