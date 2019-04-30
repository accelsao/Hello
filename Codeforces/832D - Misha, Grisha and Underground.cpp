#include <bits/stdc++.h>
#define LL long long
#define Accel ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define Re(a,b) memset(a,b,sizeof a)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define ALL(X) (X).begin(), (X).end()
#define FOR(I, A, B) for (int I = (A); I <= (B); I++)
#define REP(I, N) for (int I = 0; I < (N); I++)
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
const int N=1e5+1;
const int M=1e9+7;
int dep[N],p[N][20];
void get(int x){
	if(dep[x])return ;
	get(p[x][0]);
	dep[x]=dep[p[x][0]]+1;
	for(int i=1;(1<<i)<dep[x];i++)
		p[x][i]=p[p[x][i-1]][i-1];
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int k=dep[u]-dep[v];
	for(int i=0;i<20;i++)
		if((k>>i)&1)
			u=p[u][i];
	if(u==v)return u;
	for(int i=19;~i;i--)
		if(p[u][i]!=p[v][i])
			u=p[u][i],v=p[v][i];
	return p[u][0];	
}
int cal(int f,int t,int s){
	int u=lca(s,f),v=lca(t,f);
	int ans=dep[f]-max(dep[u],dep[v])+1;//dis of lca(s,f,t)->f 
	if(u==v)ans+=dep[lca(s,t)]-dep[u];//plus lca(s,t)->lca(s,f,t)
	return ans;
}
int main(){Accel
	int n,q,s,t,f;
	cin>>n>>q;
	dep[1]=1;
	FOR(i,2,n)cin>>p[i][0];
	FOR(i,2,n)get(i);
	while(q--){
		cin>>s>>t>>f;
		int ans=max(cal(s,t,f),cal(t,s,f));
		cout<<max(ans,cal(f,s,t))<<endl;
	}
}
