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
const int N=1<<20;
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
int n,k;
vector<int>g[N];
int f[N][20];
int d[N];
void dfs(int u,int p,int dep){
	f[u][0]=p;
	d[u]=dep;
	for(auto v:g[u])
		if(v-p)
			dfs(v,u,dep+1);
}
int in[N];
int main(){Accel
    cin>>n>>k;
    REP(i,n-1){
    	int u,v;
    	cin>>u>>v;
    	g[u].PB(v);
    	g[v].PB(u);
    	
	}
	dfs(n,n,0);
	for(int j=1;j<20;j++){
		for(int i=1;i<=n;i++)
			f[i][j]=f[f[i][j-1]][j-1];
	}
	k=n-k;
	in[n]=1;
	k--;
	for(int i=n-1;i;i--){
		if(in[i])continue;
		
		if(k<=0)break;
		int u=i;
		for(int j=19;~j;j--){
			if(!in[f[u][j]])
				u=f[u][j];
		}
		if(d[i]-d[u]+1<=k){
			u=i;
			while(!in[u]){
				in[u]=1;
				k--;
				u=f[u][0];
			}
		}
		
		
	}
	vector<int>ans;
	FOR(i,1,n) 
		if(!in[i])ans.PB(i);
	for(auto x:ans)cout<<x<<" ";
}
