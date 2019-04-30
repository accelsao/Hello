#include<iostream>
using namespace std;
long long n, k, m, p[100001][2], x, top, l, r, d, s,tot;
int main() {
	cin >> n >> k >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == p[top][0])p[top][1]++;
		else p[++top][0] = x, p[top][1] = 1;
		if (p[top][1] == k)top--;
	}
	for (int i = 1; i <= top; i++)tot += p[i][1];
	l = 1, r = top;
	while (l < r&&p[l][0] == p[r][0]) {
		d = (p[l][1] + p[r][1]) % k;
		if (d) {
			p[l][1] = d, p[r][1] = 0;
			break;
		}
		l++, r--;
	}
	if (l < r) {
		for (int i = l; i <= r; i++)s += p[i][1];
		printf("%I64d\n", tot + s*(m - 1));
	}
	else {
		s = p[l][1] * m%k;
		printf("%I64d\n", s ? tot + s - p[l][1] : 0);
	}
}
