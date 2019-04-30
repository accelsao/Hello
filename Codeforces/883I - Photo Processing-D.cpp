#include <iostream>
#include<algorithm>
using namespace std;
int n, k, a[300001], l, r, m, dp[300001], p;
bool f(int m) {
	p = 0;
	for (int i = k; i <= n; i++) {
		if (a[i] - a[dp[i - k] + 1] <= m)p = i;
		dp[i] = p;
	}
	return dp[n] == n;
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	l = 0, r = a[n] - a[1];
	while (l <= r) {
		m = (l + r) / 2;
		if (f(m))r = m - 1;
		else l = m + 1;
	}
	printf("%d\n", r + 1);
}
