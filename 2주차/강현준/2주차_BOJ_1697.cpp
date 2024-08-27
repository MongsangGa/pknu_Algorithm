#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 100'000

int n, k, arr[SIZE], nx, tx;
int dx [] = {-1, 1};
int cnt;
queue<int> q;

int BFS(int x){
    int c =0;
q.push(x), arr[x] = 0;
    while (!q.empty()) {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 2; i++) {
            nx = now + dx[i], tx = 2 * now ;
            if (nx < 0 || !arr[nx]) continue;
            q.push({nx}), arr[nx]= 0, ++c;
  }
 }
 return c;
}

int main(){
    fastio;
    cin >> n >> k;

    fill(arr, arr + n, 1);
    
     int result = BFS(0); 
    if (result != -1) {
        cout << result;
    } 
    
 
}
   

