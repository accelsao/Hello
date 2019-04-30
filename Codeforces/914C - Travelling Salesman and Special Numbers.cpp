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
const int N=1e3+5;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,k;
string s;
int f[N],dp[N];
int main(){Accel
	cin>>s>>k;n=s.size();
	if(!k)return cout<<"1",0;
	FOR(i,2,n)f[i]=f[__builtin_popcount(i)]+1;
	int p=0;
	FOR(i,1,n){
		for(int j=n;j;j--)(dp[j]+=dp[j-1])%=M;
		//binomial coefficients c(n,r)=c(n-1,r)+c(n-1,r-1)
		
		if(s[i-1]=='1')dp[p]++,p++;
		//if i='1' than there is one way which has p-1 's 1 (x<n)
	}
	//FOR(i,0,n)cout<<dp[i]<<" ";
	dp[p]++;
	//add one which is the same as n
	int ans=0;
	FOR(i,1,n)if(f[i]==k-1)ans=(ans+dp[i])%M;
	if(k==1)ans=(ans-1+M)%M;//dp[0]=1&&f[0]==0  so we need to substract it
	cout<<ans<<endl;
}
