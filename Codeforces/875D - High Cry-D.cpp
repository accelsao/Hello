#include <iostream>
#include<stack>
using namespace std;
#define N 200001
#define LL long long
int a[200001], n, L[N], R[N];
stack<int>q, p;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		while (q.size() && (a[q.top()] | a[i]) == a[i] && a[q.top()] != a[i])q.pop();
		L[i] = q.size() ? q.top() + 1 : 1;
		q.push(i);
		int j = n + 1 - i;
		while (p.size() && (a[p.top()] | a[j]) == a[j])p.pop();
		R[j] = p.size() ? p.top() - 1 : n;
		p.push(j);
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
		ans += (LL)(i - L[i])*(R[i] - i) + R[i] - L[i];
	printf("%I64d\n", (LL)n*(n - 1) / 2 - ans);
}
