#include <iostream>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int n, k, g ,add, nextnum;
int count = 0;

int main(){
    fastio;

    cin >> n;

    if(n < 10)
      // n이 10보다 작을 경우
    // 다음 수가 처음 수와 같을 때
    while(n == nextnum){

    k = n / 10;
    g = n % 10; // 자릿수 나누기

    add = k + g; // 수 더하기

    nextnum = g + add;// 다음 수 결정

   count +=; // count 증가
  }
  cout << count; // 최종 count 값 출력
}
//뭔가 이런식으로 선언을 하면 될거 같다고 생각해서 했는데 이것들을 어떤식으로 연결을 시켜야 할지 감이 안잡히네요..