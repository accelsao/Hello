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
//const double eps=1e-6;
//typedef complex<double>C;
//const double PI(acos(-1.0));
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
const int N=123456;
const int M=1e9+7;
int dp[1<<20][77];
int a[77];
int n;
int go(int mask,int i){
	int cnt=__builtin_popcount(mask);
	if(i==n){
		if(cnt>0&&(mask==(1<<cnt)-1))
			return 1;
		return 0;
	}
	if(dp[mask][i]!=-1)return dp[mask][i];
	int ans=0;
	if(a[i]==0)
		ans=go(mask,i+1);
	else{
		int num=0;
		int j=i;
		while(1){
			num<<=1;
			num+=a[j];
			if(num>20)break;
			ans+=go(mask|(1<<(num-1)),j+1);
			ans%=M;
			j++;
			if(j==n)break;
		}
		if(cnt>0&&mask+1==(1<<cnt))ans++;
	}
	return dp[mask][i]=ans;
}
int main(){Accel
	Re(dp,-1);
	cin>>n;
	string s;
	cin>>s;
	REP(i,n){
		a[i]=s[i]-'0';
	}
		
	int ans=0;
	REP(i,n)
		ans=ans+go(0,i),ans%=M;
	cout<<ans<<endl;
}
