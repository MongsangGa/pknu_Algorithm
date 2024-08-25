#include <bits/stdc++.h>
using namespace std;

#define SIZE 102

int n, m, k, len, cnt=0, dx[]={-1,0,1,0}, dy[]={0,-1,0,1};;
vector<vector<char>> arr;
char word[SIZE];
queue<pair<int, int>> q;
int visited[SIZE][SIZE];

int findWord(int a, int b){
    q.push({a, b});
    visited[a][b]=1;

    int nowLen=1;

    while(!q.empty()){
        auto now=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            for(int step=1;step<k;step++){
                int NewX=now.first+dx[i]*step;
                int NewY=now.second+dy[i]*step;

                if (NewX >= n || NewX < 0 || NewY >= n || NewY < 0 || visited[NewX][NewY]) continue;

                if(arr[NewX][NewY]==word[nowLen]){
                    q.push({NewX, NewY});
                    visited[NewX][NewY]=1;
                    nowLen++;
                }
                
            }
        }
    }
    
    if(nowLen==len){
        cnt++;
    }


    return 0;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    arr.resize(n, vector<char>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf(" %c", &arr[i][j]);
        }
    }

    scanf("%s", &word);
    len=strlen(word);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == word[0]){
                findWord(i,j);
            }
        }
    }

    printf("%d", cnt);

    return 0;
}