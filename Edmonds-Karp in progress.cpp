#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
const int inf=1e9+7;
int cap[N][N];
vector<int>g[N];
int p[N]; // BFS 
int Edmonds_Karp(int s,int t){
	int flow=0;
	queue<int>q;
	while(1){
		memset(p,-1,sizeof(p));
		q.push(s);
		while(q.size()&&p[t]==-1){
			int u=q.front();q.pop();
			for(auto v:g[u]){
				if(p[v]==-1&&cap[u][v]>0){
					p[v]=u;
					q.push(v);
				}
			}
		}
		if(p[t]==-1)break;
		int df=inf;
		int u=t;
		while(u!=s){
			int v=p[u];
			df=min(df,cap[v][u]);
		}
		u=t;
		while(u!=s){
			int v=p[u];
			cap[v][u]-=df;
			cap[u][v]+=df;
		}
		flow+=df;
	}
	return flow;
}

int main(){
	int n,m,s,t;
	cin>>n>>m>>s>>t;
	int u,v,c;
	for(int i=0;i<n;i++)g[i].clear();
	for(int i=0;i<m;i++){
		cin>>u>>v>>c;
		u--,v--;
		cap[u][v]=c;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	cout<<Edmonds_Karp(s,t)<<endl;
}
/*
// n(node),m(edge),s(source),t(target)
5 5 1 4
1 3 2
2 4 9
1 5 1
2 3 10
2 1 5
*/

