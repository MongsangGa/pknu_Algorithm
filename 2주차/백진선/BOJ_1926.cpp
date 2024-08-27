#include <bits/stdc++.h>
using namespace std;
#define SIZE 501

int n, m, dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int cnt=0, S, maxS=0;
vector<vector<int>> arr;
queue<pair<int, int>> q;


int main(){
    scanf("%d %d", &n, &m);
    arr.resize(n);
    for(int i=0;i<n;i++){
        arr[i].resize(m);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                S=1;
                q.push({i,j});
                arr[i][j] = 0;

                while(!q.empty()){
                    auto pos = q.front();
                    q.pop();

                    for(int k=0;k<4;k++){
                        int newX = pos.first+dx[k], newY = pos.second+dy[k];
                        if (newX < 0 || newY < 0 || newX >= n || newY >= m || arr[newX][newY] == 0) continue;
                        q.push({newX, newY});
                        arr[newX][newY] = 0;
                        S++;
                    }
                }
                
                maxS = max(S, maxS);
                cnt++;
            }
        }
    }

    printf("%d\n%d", cnt, maxS);

    return 0;
}