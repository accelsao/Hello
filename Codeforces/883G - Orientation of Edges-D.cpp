#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1; 
int n,m,s,x,y,t,vis[N];
vector<int>g[2][N];
set<pair<int,int>>E;
int dfs(int u,int t){
	vis[u]=1;
	int sz=1;
	for(int k=0;k<t;k++)
		for(auto v:g[k][u]){
			if(vis[v])continue;
			E.insert({u,v});
			sz+=dfs(v,t);
		}
	return sz;
}
int main(){
	cin>>n>>m>>s;
	vector<pair<int,int>>U;
	for(int i=0;i<m;i++){
		cin>>t>>x>>y;t--;
		if(t)
			g[t][y].push_back(x),U.emplace_back(x,y);
		g[t][x].push_back(y);
	}
	cout<<dfs(s,2)<<endl;
	for(auto x:U)
		putchar(E.count(x)?'+':'-');
	puts("");
	memset(vis,0,sizeof vis);
	cout<<dfs(s,1)<<endl;
	for(auto x:U)
		putchar(vis[x.second]?'+':'-');
	puts("");	
}
