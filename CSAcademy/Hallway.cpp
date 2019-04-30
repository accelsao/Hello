#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5001;
ll f[MAXN];
ll x[MAXN], y[MAXN];
int w[MAXN];
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	ll ans = 1LL*m*m;
	for (int i = 0; i < k; i++){
		cin >> x[i] >> y[i];
		f[i] = y[i]*y[i];
	}
	for (int iter = 0; iter < k; iter++){
		int v = -1;
		for (int i = 0; i < k; i++){
			if (w[i]) continue;
			if ((v == -1) || (f[i] < f[v])) v = i;
		}
		w[v] =1;
		for (int i = 0; i < k; i++){
			f[i] = min(f[i], max(f[v], (x[i] - x[v]) * (x[i] - x[v]) + (y[i] - y[v]) * (y[i] - y[v])));
		}
		ans = min(ans, max(f[v], 1LL*(m - y[v]) * (m - y[v])));
	}
	printf("%.8lf\n",sqrt(ans)/2.0);
}
