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
const int N=1e4+1;
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
int a[N],n,m,tot;
int rt[N*20],lc[N*20],rc[N*20],s[N*20];
void in(int &c,int p,int l,int r,int x){
	c=++tot;
	lc[c]=lc[p];
	rc[c]=rc[p];
	s[c]=s[p]+1;
	if(l==r)return ;
	int m=l+r>>1;
	if(x<=m)in(lc[c],lc[p],l,m,x);
	else in(rc[c],rc[p],m+1,r,x);
}
int find(int c,int p,int l,int r,int x){
	if(l==r)return s[c]-s[p];
	int m=l+r>>1;
	if(x<=m)return find(lc[c],lc[p],l,m,x);
	return find(rc[c],rc[p],m+1,r,x)+s[lc[c]]-s[lc[p]];
}
int main(){Accel
	cin>>n>>m;
	FOR(i,1,n){
		cin>>a[i];
		in(rt[i],rt[i-1],1,n,a[i]);
	}
	REP(i,m){
		int l,r,x;
		cin>>l>>r>>x;
		if(find(rt[r],rt[l-1],1,n,a[x])==x-l+1)
			puts("Yes");
		else puts("No");
	}
}
