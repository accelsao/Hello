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
const int N=100005;
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
int n,q;
int rt=1;
int tr[N<<2],sm[N<<2],D[N<<2];
void build(int rt,int l,int r){
	tr[rt]=l;
	if(l==r)return ;
	int m=l+r>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
}
void up(int L,int R,int k,int d){
	int l=L+rt-1;
	int r=R+rt+1;
	while(l^r^1){
		if(~l&1)
			sm[l^1]+=k+(tr[l^1]-L)*d,D[l^1]+=d;
		if(r&1)
			sm[r^1]+=k+(tr[r^1]-L)*d,D[r^1]+=d;
		l>>=1,r>>=1;
	}
}
int find(int p){
	int s=0;
	for(int i=p+rt;i>=1;i>>=1){
		s+=sm[i]+(p-tr[i])*D[i];
	}
	return s;
}
int main(){Accel
	cin>>n>>q;
	
	while(rt<=n+1)rt<<=1;
	build(1,1,rt);
	FOR(i,1,n)cin>>sm[i+rt];
	REP(i,q){
		int t,l,r,k,d;
		cin>>t;
		if(t==1){
			cin>>l>>r>>k>>d;
			up(l,r,k,d);
		}
		else{
			int p;
			cin>>p;
			cout<<find(p)<<endl;
		}
	}
}
