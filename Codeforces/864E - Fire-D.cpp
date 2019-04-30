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
const int N=2e6+1;
const int M=1e9+7;
struct item{
	int t,d,v,id;
}p[N];
bool cmp(item a,item b){
	//if(a.d!=b.d)
	return a.d<b.d;
	//if(a.t!=b.t)return a.t<b.t;
	//return a.d>b.d;
}
int dp[2001];
vector<int>idp[2001],s;
int main(){Accel
	int n;
	cin>>n;
	REP(i,n)cin>>p[i].t>>p[i].d>>p[i].v,p[i].id=i+1;
	sort(p,p+n,cmp);
	//REP(i,n)cout<<p[i].v<<endl;
	int k=0,ans;
	REP(i,n){
		for(int j=p[i].d-1;j>=p[i].t;j--)
			if(dp[j]<dp[j-p[i].t]+p[i].v){
				dp[j]=dp[j-p[i].t]+p[i].v;
				idp[j]=idp[j-p[i].t];
				idp[j].PB(p[i].id);
			}
	}
	int mx=0;
	REP(i,2001)if(dp[i]>mx){
		mx=dp[i];
		s=idp[i];
	}
	cout<<mx<<endl;
	cout<<s.size()<<endl;
	for(auto x:s)cout<<x<<" ";
	cout<<endl;
}
