#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int arr[100003], psum[100003];
    int N, M;

    cin >> N >> M;
    for(int i=1;i<=N;i++)
        cin>>arr[i];
    psum[1] = arr[1];
    for(int i=2;i<=N;i++)
        psum[i] = psum[i-1] + arr[i];
    while(M--) {
        int i, j;
        cin>>i>>j;
        cout<<psum[j] - psum[i-1] << '\n';
    }
    return 0;
}