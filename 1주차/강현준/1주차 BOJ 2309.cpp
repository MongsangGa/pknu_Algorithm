#include <iostream>
#include <algorithm>
using namespace std;
#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

int arr[9], sum;

void f(){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(i == j) continue;
            if(sum - (arr[i] + arr[j]) == 100){
                arr[i] = arr[j] = -1;
                return;
            }
        }
    }
}
int main(){
    fastio;

   for (int i = 0; i < 9; i++){
        cin >> arr[i];
        sum += arr[i];
}

f();
sort(arr, arr + 9);


   for (int i = 2; i < 9; i++)
    cout << arr[i] << '\n';
    return 0;

}