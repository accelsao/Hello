#include<iostream>
using namespace std;
int n, x, t, s, p, a[300001];
int main() {
	scanf("%d",&n); p = n;
	for (int i = 1; i <= n;i++) {
		scanf("%d", &x); a[x] = 1;
		printf("%d ", i - s);
		while (a[p])p--, s++;
	}
	puts("1");
}
x
