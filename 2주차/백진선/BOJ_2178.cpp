#include <bits/stdc++.h>
using namespace std;

#define SIZE 101

int n, m, visited[SIZE][SIZE];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
vector<vector<char>> input;
vector<vector<int>> arr;
queue<pair<int, int>> q;

int main(){
    scanf("%d %d", &n, &m);
    input.resize(n, vector<char>(m));
    arr.resize(n, vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c", &input[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = input[i][j]-'0';
        }
    }

    
    q.push({0,0});
    visited[0][0]=1;


    while(!q.empty()){
        auto pos = q.front();
        q.pop();

        if(pos.first == n-1 && pos.second == m-1){
            printf("%d", visited[pos.first][pos.second]);
            return 0;
        }
        

        for(int i=0;i<4;i++){
            int newX=pos.first+dx[i];
            int newY=pos.second+dy[i];

            if (newX>=0 && newY>=0 && newX<n && newY<m && arr[newX][newY]==1 && visited[newX][newY]==0) {
                q.push({newX,newY});
                visited[newX][newY] = visited[pos.first][pos.second] + 1;
            }
        }
    }

    printf("%d\n", visited[n-1][m-1]);

    return 0;
}