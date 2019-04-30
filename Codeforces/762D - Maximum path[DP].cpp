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
//for(int mask=i;mask>0;mask=(mask-1)&i)
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//__gcd, atan2(y,x)=y/x , __int128
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
LL pw(LL a,LL b){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
//log() = ln() , log(x)/log(y)=log(y)-base-x
//INT_MAX 127,INT_MIN 128
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)

LL f[4][N];
int p[4][N];
int m;
LL inf=-(1LL<<60);
int main(){
	cin>>m;
	FOR(i,1,3)
		FOR(j,1,m){
			cin>>p[i][j];
			f[i][j]=inf;
		}
	FOR(i,1,3)f[i][0]=inf;
	
	LL s1=inf,s2=inf;
	f[1][0]=0;
	FOR(j,1,m){
		
		
		f[2][j]=max(f[2][j],f[2][j-1]+p[2][j]);//左 
		f[2][j]=max(f[2][j],f[1][j-1]+p[1][j]+p[2][j]);//左上+上 
		f[2][j]=max(f[2][j],f[3][j-1]+p[3][j]+p[2][j]);//左下+下 
		
		f[1][j]=max(f[1][j],f[1][j-1]+p[1][j]);
		f[1][j]=max(f[1][j],f[2][j-1]+p[2][j]+p[1][j]);//左下+下 
		
		
		
		f[3][j]=max(f[3][j],f[3][j-1]+p[3][j]);
		f[3][j]=max(f[3][j],f[2][j-1]+p[3][j]+p[2][j]);
		
		//三列總和 上到下 和 下到上 
		LL t=max(s1,s2);
		s1=max(s1,max(t,f[1][j-1]));
		s2=max(s2,max(t,f[3][j-1]));
		FOR(i,1,3){
			s1+=p[i][j];
			s2+=p[i][j];
		}
		f[3][j]=max(f[3][j],s1);
		f[1][j]=max(f[1][j],s2);
		
	
	
	}
	cout<<f[3][m]<<endl;
}
//-------------------------------
#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int n;
LL a[4][100005];
LL dp[4][100005];
LL l,r,dq;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=3;++i) 
		for (int j=1;j<=n;++j) scanf("%I64d",&a[i][j]);
	for (int i=1;i<=3;++i)
		for (int j=0;j<=n;++j) dp[i][j]=-1e18;
	dp[1][0]=0;
	for (int i=1;i<=n;++i)
	{
		for (int j=1;j<=3;++j)
			for (int k=1;k<=3;++k)
			{
				l=min(j,k);r=max(j,k);dq=0;
				for (int p=l;p<=r;++p)  dq+=a[p][i];
				dp[j][i]=max(dp[j][i],dp[k][i-1]+dq);
			}
		if (i>=2)
		{
			dq=0;
			for (int j=1;j<=3;++j) dq+=a[j][i-1]+a[j][i];
			dp[1][i]=max(dp[1][i],dp[3][i-2]+dq);
			dp[3][i]=max(dp[3][i],dp[1][i-2]+dq);
		}
	}
	printf("%I64d\n",dp[3][n]);
	return 0;
}
