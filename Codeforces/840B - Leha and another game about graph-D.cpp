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
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
const int N=3e5+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,m;
int d[N];
vector<int>ans;
vector<PII>g[N];
int vis[N];
int dfs(int u){
	vis[u]=1;
	int t=d[u];
	for(auto i:g[u])
		if(!vis[i.F]&&dfs(i.F)){
			ans.PB(i.S);
			t^=1;
		}
	return t;
}
int main(){Accel
	cin>>n>>m;
	int dt=0,f=0;
	FOR(i,1,n){
		cin>>d[i];
		if(~d[i])dt^=d[i];
		else d[i]=0,f=i;
	}
	if(dt && !f)return cout<<-1,0;
	if(f)d[f]=dt;
	FOR(i,1,m){
		int u,v;
		cin>>u>>v;
		g[u].PB({v,i});
		g[v].PB({u,i});
	}
	dfs(1);
	cout<<ans.size()<<endl;
	for(auto x:ans)cout<<x<<endl;
}
