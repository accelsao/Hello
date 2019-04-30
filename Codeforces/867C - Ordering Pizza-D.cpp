#include<iostream>
#include<algorithm>
#define N 100001
using namespace std;
struct P {
	long long s, a, b, d;
	bool operator<(const P x)const {
		if (d == x.d)
			return a > x.a;
		return d < x.d;
	}
}p[N];
long long n, k, ans, tot, l, r, T = 2, t1, tmp, d;
int main() {
	scanf("%I64d%I64d", &n, &k);
	for (int i = 0; i < n; i++) {
		cin >> p[i].s >> p[i].a >> p[i].b, p[i].d = p[i].b - p[i].a, tot += p[i].s;
		if (p[i].d < 0)t1 += p[i].s;
	}
	d = (k - tot%k)%k, tot += d;
	p[n++] = P{ d,0,0 };
	sort(p, p + n);
	while (T--) {
		l = (t1 / k + T)*k, r = tot - l, tmp = 0;
		for (int i = 0; i < n; i++) {
			d = p[i].s - l;
			if (d <= 0)tmp += p[i].a*p[i].s, l = -d;
			else if (l)tmp += p[i].a*l + p[i].b*d, r -= d, l = 0;
			else tmp += p[i].b*p[i].s;
		}
		ans = max(ans, tmp);
	}
	printf("%I64d\n", ans);
}
