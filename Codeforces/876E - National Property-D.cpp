#include<iostream>
#include<vector>
#define N 100005
using namespace std;
vector<int> G[N];
int a[N], b[N], pre, len, c, p[N], n, m, s, t, f, v[N];
void D(int x) {
	p[c++] = x; v[x] = 1;
	f |= x == t;
	for (int d:G[x])
		if (!v[d])
			D(d);
}
int main() {
	cin >> n >> m;
	t = m + 1;
	cin >> pre;
	for (int i = 1; i <= pre; i++)cin >> a[i];
	for (int i = 2; i <= n; i++){
		cin >> len;
		for (int i = 1; i <= len; i++)cin >> b[i];
		int q = 1;
		while (a[q] == b[q] && q <= len)q++;
		if (q <= pre && q>len)exit(puts("No"));
		if (q <= pre && q <= len){
			if (a[q]>b[q])
				G[s].push_back(a[q]), G[b[q]].push_back(t);
			else G[b[q]].push_back(a[q]);
		}
		pre = len;
		for (int i = 1; i <= len; i++)a[i] = b[i];
	}
	D(s);
	if (f)puts("No");
	else{
		puts("Yes");
		printf("%d\n", c - 1);
		for (int i = 1; i < c; i++)
			printf("%d ", p[i]);
	}
}
