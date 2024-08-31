#include <bits/stdc++.h>
using namespace std;

#define SIZE 503

int n, visited[SIZE][SIZE];
vector<vector<int>> arr;
int dx[]={-1,0,1,0},  dy[]={0,-1,0,1};
queue<pair<int, int>> q;
int big=INT_MIN;

int eat(int a, int b){
    int maxN=1;
    q.push({a,b});
    visited[a][b]=1;

    while(!q.empty()){
        auto now = q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int NewX = now.first + dx[i];
            int NewY = now.second + dy[i];

            if(NewX>=n || NewY>=n || NewX<0 || NewY<0 || visited[NewX][NewY]) continue;

            if(arr[NewX][NewY] > arr[now.first][now.second]){
                q.push({NewX, NewY});
                visited[NewX][NewY]=1;
                maxN++;
            } else continue;
        }
    }

    if(maxN>big){
        big=maxN;
    }

    return 0;


}

int main(){
    scanf("%d", &n);
    arr.resize(n, vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            eat(i, j);
        }
    }

    printf("%d", big);
    
    return 0;
}