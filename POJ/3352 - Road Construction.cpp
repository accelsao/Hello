#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<functional>
#include<fstream>
#include<stack>
#include<ctime>
#include<vector>
#define accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define N 1010
vector<int>g[N * 2];
int n, m, tot, dfs_n, bcc_c, top, bnum;
int df[N], belong[N], deg[N], sta[N], brd[N][2];
void init(){
	tot = 0;
	int u, v;
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}
int dfs(int u, int p){
	int lwu = df[u] = ++dfs_n;
	sta[++top] = u;
	for (int i = 0; i < g[u].size(); i++){
		int v = g[u][i];
		if (!df[v]){
			int lwv = dfs(v, u);
			lwu = min(lwu, lwv);
			if (lwv>df[u]){
				brd[bnum][0] = u;
				brd[bnum++][1] = v;
				bcc_c++;
				while (1){
					int x = sta[top--];
					belong[x] = bcc_c;
					if (x == v) break;
				}
			}
		}
		else if (v != p&&df[v] < df[u])
			lwu = min(lwu, df[v]);
	}
	return lwu;
}
int main() {
	accel;
	while (cin >> n >> m){
		init();
		memset(deg, 0, sizeof(deg));
		memset(df, 0, sizeof(df));
		dfs_n = bcc_c = top = bnum = 0;
		dfs(1, -1);
		if (top){
			bcc_c++;
			while (1){
				int x = sta[top--];
				belong[x] = bcc_c;
				if (x == 1) break;
			}
		}
		for (int i = 0; i < bnum; i++){
			int u = brd[i][0];
			int v = brd[i][1];
			deg[belong[u]]++;
			deg[belong[v]]++;
		}
		int leaf = 0;
		for (int i = 1; i <= bcc_c; i++)
			if (deg[i] == 1)
				leaf++;
		leaf = (leaf + 1) >> 1;
		printf("%d\n", leaf);
	}
}
----------------------------------------------------------------------------------------------------------------------------------------
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<string>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include<vector>
#include<functional>
#include<fstream>
#include<stack>
#include<ctime>
#include<vector>
#define accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
#define N 1010
vector<int>g[N * 2];
int n, m, tot, dfs_n, bcc_c, top, bnum;
int df[N], lw[N], deg[N], vis[N];
void init(){
	tot = 0;
	int u, v;
	for (int i = 0; i <= n; i++)
		g[i].clear();
	for (int i = 0; i < m; i++){
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
}
void dfs(int u, int p){
	lw[u] = df[u] = ++dfs_n;
	vis[u] = 1;
	for (int i = 0; i < g[u].size(); i++){
	
		int v = g[u][i];
		if (v == p)continue;
		if (!vis[v]){
			dfs(v, u);
			lw[u] = min(lw[u], lw[v]);
		}
		else if (vis[v] == 1)
			lw[u] = min(lw[u], df[v]);
	}
	vis[u] = 2;
}
int main() {
	accel;
	while (cin >> n >> m){
		init();
		memset(deg, 0, sizeof(deg));
		memset(lw, 0, sizeof(lw));
		memset(df, 0, sizeof(df));
		memset(vis, 0, sizeof(vis));
		dfs_n = bnum = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i])
				dfs(i, -1);
		for (int u = 1; u <= n; u++)
			for (int j = 0; j < g[u].size(); j++){
				int v = g[u][j];
				if (lw[u] != lw[v])
					deg[lw[u]]++;
			}
		int leaf = 0;
		for (int i = 1; i <= n; i++)
			if (deg[i] == 1)
				leaf++;
		leaf = (leaf + 1) >> 1;
		printf("%d\n", leaf);
	}
}
