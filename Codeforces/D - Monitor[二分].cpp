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
const int N=600;
const int M=1e9+7;
const double eps=1e-6;
typedef complex<double>C;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int t=0;while(x){t+=BIT[x];x-=x&-x;}return t;}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
int p[N][N];
int n,m,k,q;
int f[N][N];
struct A{
	int x,y,d;
}Q[N*N];
bool cmp(A a,A b){
	return a.d<b.d;
}
bool g(int lim){
	FOR(i,1,n)
		FOR(j,1,m)
			f[i][j]=p[i][j]=0;
	REP(i,q){
		if(Q[i].d<=lim)
			p[Q[i].x][Q[i].y]=1;
	}
	FOR(i,1,n)
		FOR(j,1,m){
			f[i][j]=f[i-1][j]+f[i][j-1]+p[i][j]-f[i-1][j-1];
			if(i>=k&&j>=k)
				if(f[i][j]-f[i-k][j]-f[i][j-k]+f[i-k][j-k]==k*k){
					return 1;
				}
		}
	return 0;	
}
int main(){Accel
	cin>>n>>m>>k>>q;
	if(q<k*k){
		cout<<-1<<endl;
		return 0;
	}
	REP(i,q){
		cin>>Q[i].x>>Q[i].y>>Q[i].d;
	}
	int l=0,r=1e9,md;
	int ans=-1;
	while(l<=r){
		md=l+r>>1;
		if(g(md)){
			ans=md;
			r=md-1;
		}
		else l=md+1;
	}
	
	cout<<ans<<endl;
}
