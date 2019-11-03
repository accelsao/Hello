#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define F first
#define S second
using ll = long long;
const int N = 3e5 +10;
const int M = 1e9 + 7;
const int inf = 1e9+7;
const ll INF = 1e18;

vector<int> g[N];
int vis[N], low[N], dfn;
int mx[N];
int ans;
void dfs(int u, int p){
	vis[u]=low[u]=++dfn;
	for(const int& v:g[u]){
		if(v!=p){
			if(vis[v]){
				low[u]=min(low[u], vis[v]);
				
			}
			else{
				dfs(v, u);
				ans=max(ans, mx[u]+mx[v]+(low[v]>vis[u]));
				mx[u]=max(mx[u], mx[v]+(low[v]>vis[u]));
				low[u]=min(low[u], low[v]);
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n, m;
	cin>>n>>m;
	int u, v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, 1);
	printf("%d\n", ans);
}
