#include<iostream>      
#include<algorithm>    
#include<vector>
#include<stack>
#include<cstring>
using namespace std;
#define LL long long
const int N = 1e6 + 1;
int n, m, s, x, y, w;
struct road {
	int v; LL w;
};
vector<road>g[N], G[N];
int lw[N], vis[N], dft, belong[N], scc;
LL pt[N], dis[N];
stack<int>sk;
void tarjan(int u) {
	vis[u] = lw[u] = ++dft;
	sk.push(u);
	for (auto i : g[u]) {
		if (!vis[i.v])
			tarjan(i.v),
			lw[u] = min(lw[u], lw[i.v]);
		else if (!belong[i.v])
			lw[u] = min(lw[u], vis[i.v]);
	}
	if (lw[u] == vis[u]) {
		belong[u] = ++scc;
		while (sk.top() != u)
			belong[sk.top()] = scc, sk.pop();
		sk.pop();
	}
}
LL dfs(int u) {
	if (dis[u])return dis[u];
	LL ans = 0;
	for (auto i : G[u])
		ans = max(ans, dfs(i.v) + i.w);
	return dis[u] = ans + pt[u];
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &x, &y, &w);
		g[x].push_back({ y,w });
	}
	scanf("%d", &s);
	tarjan(s);
	for (int i = 1; i <= n; i++)
		for (auto j : g[i]) {
			x = belong[i], y = belong[j.v];
			if (x == y) {
				LL t = floor((sqrt(8 * j.w + 1) - 1) / 2);
				pt[x] += j.w*(t + 1) - t*(t + 1)*(t + 2) / 6;
			}
			else
				G[x].push_back(road{ y,j.w });
		}
	cout << dfs(belong[s]);
}
//二分搜
LL cal(LL x){
	LL l=0,r=30000,m;
	while(l+1<r){
		m=l+r>>1;
		if(x>=m*(m+1)/2)
			l=m;
		else r=m;
	}
	return (l+1)*x-l*(l+1)*(l+2)/6;
}
//公式解 求m
LL m = floor((sqrt(8 * j.w + 1) - 1) / 2);
