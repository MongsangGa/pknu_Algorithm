#include <bits/stdc++.h>

int n, m, a, b, arr[100003], psum[100003];
 
int main() {
	scanf("%d %d", &n, &m);
	for (int i=0; i<n; i++)
		scanf("%d", &arr[i]);
	psum[0] = arr[0];
	for(int i=1;i<n;i++)
		psum[i] = psum[i-1] + arr[i];
	for(int i=0;i<m;i++){
		scanf("%d %d", &a, &b);
		printf("%d\n", psum[b-1]-psum[a-2]);
		}
	return 0;
}
