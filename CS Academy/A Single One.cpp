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
//#pragma GCC optimize(2)
using namespace std;
const int N=1e6+1;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
//INT_MAX 127,INT_MIN 128
int n,m,k,s;
int p[N],ans[N];
int x[N];
inline int find(int x){
	if(x==p[x])return x;
	return p[x]=find(p[x]);
}
int main(){Accel
	cin>>n>>k>>m>>s;
	FOR(i,1,n+2)p[i]=i;
	REP(i,m){
		int x;cin>>x;p[x]+=2;
	}
	FOR(i,1,n)ans[i]=-1;
	int t=0,e=1;
	x[0]=s;
	p[s]+=2;
	ans[s]=0;
	while(t<e){
		int l=max(1,x[t]-k+1);
		int r=min(n-k+1,x[t]);
		int from=l+l+k-1-x[t];
		int to=r+r+k-1-x[t];
		int cur=find(from);
		while(cur<=to){
			x[e]=cur;
			ans[x[e]]=ans[x[t]]+1;
			e++;
			p[cur]=cur+2;
			cur=find(cur);
		}
		t++;
	}
	FOR(i,1,n)
		cout<<ans[i]<<" ";
}
