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
const int N=1e5+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,m,d[N];
vector<int>lev[N];
set<int>g[N];
LL ans;
int main(){Accel
    cin>>n>>m;
    set<int>ds;
    FOR(i,1,n){
        int x;
        cin>>d[i];
        ds.insert(d[i]);
        lev[d[i]].PB(i);
    }
    int mx=*ds.rbegin();
    if(mx+1!=ds.size()){cout<<"0";return 0;}
    if(lev[0].size()>1){cout<<"0";return 0;}
    FOR(i,1,m){
        int u,v;
        cin>>u>>v;
        g[u].insert(v);
        g[v].insert(u);
        if(abs(d[u]-d[v])>1){cout<<"0";return 0;}
    }
    ans=1;
    FOR(i,1,mx){
    	LL tmp=0,k=lev[i].size();
    	for(auto x:lev[i])
    		for(auto to:g[x])if(d[to]==i)tmp++;
    	tmp>>=1;
    	tmp=k*(k-1)/2-tmp;
    	ans=ans*pw(2,tmp,M)%M;
    	k=lev[i-1].size();
    	for(int x:lev[i]){
			LL c=0;
			for(int to:g[x])if(d[to]==i-1)c++;
			tmp=pw(2,k-c,M);
			if(!c)tmp--;
			tmp+=M;tmp%=M;
			ans=ans*tmp%M;
		}
	}
	cout<<ans<<endl;
}
