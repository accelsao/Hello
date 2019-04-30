#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=1e9+7;
int n,m,k,x,sz[N];
#define LL long long
LL f[N][12][3],t[12][3];
vector<int>g[N];
inline void add(LL &x,LL y) {
	x=(x+y)%mod;
}
void dfs(int u,int p){
	f[u][0][0]=k-1;
	f[u][1][1]=1;
	f[u][0][2]=m-k;
	sz[u]=1;
	for(auto v:g[u]){
		if(v==p)continue;
		dfs(v,u);
		memset(t,0,sizeof(t));
		for(int j=0;j<=min(x,sz[u]);j++)
			for(int k=0;k<=min(x-j,sz[v]);k++){
				add(t[j+k][0],f[u][j][0]*(f[v][k][0]+f[v][k][1]+f[v][k][2])%mod);
				add(t[j+k][1],f[u][j][1]*(f[v][k][0]                      )%mod);
				add(t[j+k][2],f[u][j][2]*(f[v][k][0]+          +f[v][k][2])%mod);
			}
			sz[u]+=sz[v];
			memcpy(f[u],t,sizeof(f[u]));
	}	
}
int main(){
	cin>>n>>m;
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cin>>k>>x;
	dfs(1,0);
	LL ans=0;
	for(int i=0;i<=x;i++)
		for(int j=0;j<3;j++)
			add(ans,f[1][i][j]);
	cout<<ans<<endl;	
}
