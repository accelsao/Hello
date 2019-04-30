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
#define SZ(a) ((int)a.size())
using namespace std;
const int N=1e3+10;
const int M=1e9+7;
const double eps=1e-6;
const double PI(acos(-1.0));
//size() use int
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln()
//watch out LL
int n,m,k;
int a[N];
vector<int>d;
vector<int>g[N];
int dfs(int u){
	if(!a[u])return 0;
	int s=1;
	a[u]=0;
	for(auto v:g[u])s+=dfs(v);		
	return s;
}
int main(){Accel
	cin>>n>>m>>k;
	int x;
	FOR(i,1,k)
		cin>>x,a[x]=1,d.PB(x);
	int u,v;
	REP(i,m){
		cin>>u>>v;
		a[u]=a[v]=1;
		g[u].PB(v);
		g[v].PB(u);
	}
	int z=0;
	int ans=0;
	for(auto x:d){
		int t=dfs(x);		
		z=max(z,t);
		n-=t;
		ans+=t*(t-1)/2;
	}
	n+=z;//保留最大推 
	cout<<ans-z*(z-1)/2+n*(n-1)/2-m;
}
