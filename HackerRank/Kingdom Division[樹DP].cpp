#include <bits/stdc++.h>
#define ld long double
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
//typedef complex<double>C;
//const double PI(acos(-1.0));
//const double eps(1e-8);
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){int s=0;while(x){s+=BIT[x];x-=x&-x;}return s;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
const int N=1234567;
const int M=1e9+7;
int n;
vector<int>g[N];
LL f[N][2][2];
void dfs(int u,int p){
	
	f[u][0][1]=1;
	f[u][1][1]=1;
	for(auto v:g[u])
		if(v-p){
			dfs(v,u);
			
			f[u][0][0]=f[u][0][0]*(f[v][1][0]+f[v][0][0]+f[v][0][1])%M;
			f[u][0][0]+=f[u][0][1]*(f[v][0][0]+f[v][0][1])%M;
			f[u][0][0]%=M;
			
			f[u][1][0]=f[u][1][0]*(f[v][0][0]+f[v][1][0]+f[v][1][1])%M;
			f[u][1][0]+=f[u][1][1]*(f[v][1][0]+f[v][1][1])%M;
			f[u][1][0]%=M;
			
			f[u][0][1]=f[u][0][1]*f[v][1][0]%M;
			f[u][1][1]=f[u][1][1]*f[v][0][0]%M;
		}
}
int main(){Accel
	cin>>n;
	REP(i,n-1){
		int u,v;
		cin>>u>>v;
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,-1);
	cout<<(f[1][0][0]+f[1][1][0])%M<<endl;
}
