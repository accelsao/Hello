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
const int N=1e5+1;
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
int n,q;
int a[N][10];
int sm[N*4][10],nt[N*4][10];
void pushup(int rt){
	REP(i,10)
		sm[rt][i]=sm[rt<<1][i]+sm[rt<<1|1][i];
}
void build(int rt,int l,int r){
	if(l==r){
		REP(i,10){
			sm[rt][i]=a[l][i];
			nt[rt][i]=i;
		}
		return ;
	}
	int m=l+r>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	pushup(rt);
}
void pd(){
	if(l!=r)
		pd()
}
void upd(int rt,int l,int r,int L,int R,int x,int y){
	if(l>=L&&r<=R)}{
		nt[rt][x]=y;
		sm[rt][y]+=sm[rt][x];
		sm[rt][x]=0;
		return ;
	}
	pd();
	int m=l+r>>1;
	
}
int main(){Accel
	cin>>n>>q;
	FOR(i,1,n){
		int x;cin>>x;
		int t=1;
		while(x){
			a[i][x%10]+=t;
			t*=10,x/=10;
		}
	}
	build(1,1,n);
	REP(i,q){
		int t,l,r,x,y;cin>>t;
		if(t==1){
			cin>>l>>r>>x>>y;
			upd(1,1,n,l,r,x,y);
		}
	}
}
