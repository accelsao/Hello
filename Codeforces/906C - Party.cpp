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
#define st 1,1,n
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
const int N=22+1;
const int M=1e9+7;
int n,m;
int g[1<<N],f[1<<N],ans,c[1<<N];
int main(){Accel
	cin>>n>>m;
	if(n*(n-1)/2==m)return cout<<0<<endl,0;
	int u,v;
	while(m--){
		cin>>u>>v;u=1<<(u-1),v=1<<(v-1);
		g[u]|=v;g[v]|=u;	
	}
	int k=n+1;
	REP(i,n)g[1<<i]|=1<<i,f[1<<i]=1;
	REP(i,1<<n)c[i]=c[i>>1]+(i&1);
	REP(s,1<<n)if(f[s]){
		REP(i,n)if((s>>i)&1)g[s]|=g[1<<i];
		REP(i,n)if((g[s]>>i)&1)f[s|(1<<i)]=1;
		if(g[s]+1==1<<n)if(c[s]<k)k=c[s],ans=s;
	}
	cout<<k<<endl;
	REP(i,n)if((ans>>i)&1)cout<<i+1<<" ";
}
