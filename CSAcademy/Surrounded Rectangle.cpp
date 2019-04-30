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
const int N=1e3+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,m;
int p[N][N];
int s[N][N];
int w[N][N],h[N][N];
int main(){Accel
	cin>>n>>m;
	FOR(i,1,n)FOR(j,1,m)cin>>p[i][j];
	FOR(i,1,n)FOR(j,1,m)s[i][j]=s[i-1][j]+s[i][j-1]+p[i][j]-s[i-1][j-1];
	FOR(i,1,n)FOR(j,1,m){
		if(p[i][j]){
			w[i][j]=1+w[i][j-1];
			h[i][j]=1+h[i-1][j];
		}	
		else w[i][j]=h[i][j]=0;
	}
	int ans=-1;
	FOR(i,2,n-1)FOR(j,2,m-1){
		int wd=w[i][j];
		int ht=h[i][j];
		if(!wd||!ht||wd==j||ht==i)continue;
		int k=wd*ht;
		int A=s[i][j]-s[i-ht][j]-s[i][j-wd]+s[i-ht][j-wd];
		int B=s[i+1][j+1]-s[i-ht-1][j+1]-s[i+1][j-wd-1]+s[i-ht-1][j-wd-1];
		if(k-A||A-B)continue;
		ans=max(ans,k);
	}
	cout<<ans<<endl;
}
