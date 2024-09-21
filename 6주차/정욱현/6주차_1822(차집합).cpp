#include <bits/stdc++.h>

using namespace std;

#define fastio cin.tie(0), ios_base::sync_with_stdio(0)

#define SIZE 500'003

int numA, numB, cnt;
int arrA[SIZE];
int arrB[SIZE];
int arrAns[SIZE];

int main(){

    fastio;
    cin >> numA >> numB; // k개의 랜선 n개의 랜선 만드는 최대길이는?

    for (int i=0; i<numA; i++)
        cin >> arrA[i];
    for (int i=0; i<numB; i++)
        cin >> arrB[i];
    sort(arrA, arrA+numA);
    sort(arrB, arrB+numB);

    cnt = 0;
    for (int i=0; i<numA; i++) {
        bool is_same = binary_search(arrB, arrB+numB, arrA[i]);
        if(!is_same){
            arrAns[cnt] = arrA[i];
            cnt += 1;
        }
    }

    cout << cnt << endl;
    for(int i=0; i<cnt; i++)
        cout << arrAns[i] << " ";
    return 0;
}