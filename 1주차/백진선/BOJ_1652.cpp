#include <bits/stdc++.h>
using namespace std;

//#define SIZE 105

int N;
vector<vector<char>> arr;
//char arr[SIZE][SIZE];

int main(){    
    scanf("%d", &N);
    arr.resize(N);
    for(int i = 0; i < N; i++) {
        arr[i].resize(N);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf(" %c", &arr[i][j]);
        }
    }

    int cnt_row=0;
    for (int i = 0; i < N; i++) {
        int cnt=0;
        for (int j = 0; j < N; j++) {
            if(arr[i][j] == '.'){
                cnt++;
            } else if(arr[i][j]=='x'){
                if(cnt>=2){
                    cnt_row++;
                }
                cnt=0;
            }       
        }
        if(cnt>=2){
            cnt_row++;
        }
    }

    int cnt_column=0;
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (arr[j][i] == '.') {
                cnt++;
            } else if (arr[j][i] == 'x') {
                if (cnt>=2) {
                    cnt_column++;
                }
                cnt=0;
            }
        }
        if(cnt>=2){
            cnt_column++;
        }
    }

    printf("%d %d", cnt_row, cnt_column);

    return 0;

}