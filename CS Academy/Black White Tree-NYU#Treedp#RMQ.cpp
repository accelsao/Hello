#include <bits/stdc++.h>
using namespace std;
const int N=5e4+10,Bucketsz=2500;
int n,x,y,vis[N];
vector<int>g[N],color;
vector<pair<int,int>>q;
int dep[N],pos[N];
vector<int>traversal;
struct Treedp{
	int num[2],sum[2];
	void merge(Treedp &son){
		for(int i=0;i<2;i++)
			num[i]+=son.num[i],
			sum[i]+=son.sum[i]+son.num[i];
	}
	void setfromfa(Treedp &fa){
		for(int i=0;i<2;i++){
			sum[i]=fa.sum[i]-num[i]+(fa.num[i]-num[i]);
			num[i]=fa.num[i];
		}
	}
	void RE(){
		for(int i=0;i<2;i++)
			num[i]=sum[i]=0;
	}
}tdp[N];
void getdep(int u){
	vis[u]=1;
	pos[u]=traversal.size();
	traversal.push_back(dep[u]);
	for(auto oth:g[u]){
		if(vis[oth])continue;
		dep[oth]=dep[u]+1;
		getdep(oth);
		traversal.push_back(dep[u]);
	}
	vis[u]=0;
}
int rmq[2*N][20];
void lca(){
	getdep(0);
	int n=traversal.size();	
	for(int i=0;i<n;i++)
		rmq[i][0]=traversal[i];
	for(int j=1;(1<<j)<=n;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<j)][j-1]);
}
void down(int u){
	vis[u]=1;
	tdp[u].RE();
	for(auto v:g[u]){
		if(vis[v])continue;
		down(v);
		tdp[u].merge(tdp[v]);
	}
	tdp[u].num[color[u]]++;
	vis[u]=0;
}
void up(int u){
	vis[u]=1;
	for(auto v:g[u]){
		if(vis[v])continue;
		tdp[v].setfromfa(tdp[u]);
		up(v);
	}
	vis[u]=0;
}
int dis(int u,int v){
	if(u==v)return 0;
	u=pos[u],v=pos[v];
	int ans=traversal[u]+traversal[v];
	if(u>v)swap(u,v);
	int i=0;
	while(1<<(i+1)<=v-u+1)i++;//v-u+1
	return ans-2*min(rmq[u][i],rmq[v-(1<<i)+1][i]);
}
void find(vector<int,int>q){
	unordered_map<int,int>ct;//color toggle
	down();
	up();
	for(auto it:q){
		int u=it->second;
		int t=it->first;
		if(!t)
			ct[u]^=1;
		else{
			int myc=ct[u]^color[u];
			auto ans=tdp[u].sum[myc];
			for(auto it:ct){
				int v=it->first;
				int c=ct[v]^color[v];
				if(!ct[v])continue;
				if(c!=myc)
					ans-=dis(u,v);
				else
					ans+=dis(u,v);
			}
			cout<<ans<<endl;
		}
	}
	for(auto it:ct)
		colot[it.first]^=it.second;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
   	int qs;
	cin>>n>>qs;
    color.resize(n);
    for(auto &it:color)cin>>it;
    for(int i=1;i<n;i++){
        cin>>x>>y;x--,y--;
        g[x].push_back(y);
        g[y].push_back(x);     
    }
    lca();
    for(int i=0;i<qs;i++){
    	int ty,node;
        cin>>ty>>node;t--;node--;
        q.push_back({t,node});
    }
    for(int i=0;i<qs;i+=Bucketsz){
		vector<int,int>Q;
		for(int j=0;j<Bucketsz;j++)
			if(i+j<qs)
				Q.push_back({q[i+j]});
		find(Q);
	}
}
