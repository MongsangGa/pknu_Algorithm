#include <bits/stdc++.h>

using namespace std;

int main () {

    int N, NN, temp;
    int ten, one;
    int count = 0;

    scanf("%d", &N);
    NN = N;

    while(N != NN || count == 0){
        ten = N / 10;
        one = N % 10;

        temp = ten + one;
            N = (one * 10) + temp % 10;
            count++;
    }

    printf("%d", count);
    
    return 0;
}