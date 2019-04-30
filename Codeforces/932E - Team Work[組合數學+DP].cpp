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
const int N=5001;
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
int f[N];
int n,k;
int pw(int x,int p){
	if(p<=0)return 1;
	if(p==1)return x;
	int ans=pw(x,p>>1);
	ans=1LL*ans*ans%M;
	if(p&1)ans=1LL*ans*x%M;
	return ans;
}
int main(){Accel
	cin>>n>>k;
	f[0]=1;
	FOR(i,1,k){
		for(int j=i;j;j--)
			f[j]=(1LL*f[j]*j+1LL*f[j-1]*(n-(j-1)))%M;
		f[0]=0;
	}
	int ans=0;
	FOR(i,1,k)
		ans=(ans+1LL*f[i]*pw(2,n-i)%M)%M;
	cout<<ans<<endl;
}
