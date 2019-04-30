#include<iostream>
#include<algorithm>
using namespace std;
const double eps = 1e-4;
#define N 400010
int n, q, ty, l1, r1, l2, r2;
double d, e, d1, nn, f, p[N], len[N], epv[N], s[N];
void pd(int a, int b){
	if (len[b]<eps){
		len[b] = len[a];
		epv[b] = epv[a];
	}
	else{
		epv[b] = (len[b] * epv[a] + (len[a] - 1) * epv[b]) / (len[a] - 1 + len[b]);
		len[b] = len[a] * len[b] / (len[a] + len[b] - 1);
	}
	/*
	pushdown
	expectation for n2 is  [len(n1)-1 ]*epv(n2)/(len(n1)-1+len(n2))  if replaced    you can seen as 1/len(n1) will not change the value so len(n1)-1
	len(n2)=(len(n1)-1)*len(n2)+1*len(n2) /(len(n1)-1+len(n2))
	*/
}
double sum(int l, int r, int n, int L, int R, int A){//A=1 sum
	if (!p[n])
		p[n] = s[r] - s[l - 1];
	int m = l + r >> 1;
	if (len[n]>eps){
		f = ((r - l + 1)*epv[n] - p[n]) / len[n];
		p[n] += f;
		if (l<r){
			pd(n, n * 2);
			pd(n, n * 2 + 1);
		}
		len[n] = epv[n] = 0;
	}
	if (l == L&&r == R){
		if (A == 0){
			epv[n] = d;
			len[n] = e;
			f = ((r - l + 1)*epv[n] - p[n]) / len[n];
			for (int i = n / 2; i; i /= 2)p[i] += f;
		}
		return p[n];
	}
	double ans = 0;
	if (L <= m) ans += sum(l, m, n * 2, L, min(m, R), A);
	if (m < R) ans += sum(m + 1, r, n * 2 + 1, max(m + 1, L), R, A);
	return ans;
}
int main(){
	cin >> n >> q;
	for (int i = 1; i <= n; i++)cin >> s[i], s[i] += s[i - 1];
	while (q--){
		cin >> ty;
		if (ty<2){
			cin >> l1 >> r1 >> l2 >> r2;
			d1 = sum(1, n, 1, l1, r1, 1);
			d = sum(1, n, 1, l2, r2, 1) / (r2 - l2 + 1);
			e = r1 - l1 + 1;
			sum(1, n, 1, l1, r1, 0);
			d = d1 / (r1 - l1 + 1);
			e = r2 - l2 + 1;
			sum(1, n, 1, l2, r2, 0);
		}
		else{
			cin >> l1 >> r1;
			printf("%.7lf\n", sum(1, n, 1, l1, r1, 1));
		}
	}
}
