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
//isalnum() decimal digit or an uppercase or lowercase letter
//int dw[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
//int dw[8][2]={{0,1},{1,0},{0,-1},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
//cout<<fixed<<setprecision(12)<<ans<<endl;
//__builtin_popcount(mask)
const int N=3005;
int n,M;
LL c[N][N];
LL s[N][N];
LL p2[N];
LL pw(LL a,LL b,LL M){LL t=1;for(;b;b>>=1,a=a*a%M)b&1?t=t*a%M:0;return t;}
int main() {
	cin>>n>>M;
	p2[0]=1;
	FOR(i,1,n){
		c[i][0]=c[i][i]=1;
		FOR(j,1,i-1){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=M;
		}
		p2[i]=p2[i-1]*2%M;
	}
	s[0][0]=1;
	FOR(i,1,n+1)
		FOR(j,1,i+1){
			s[i][j]=s[i-1][j-1]+s[i-1][j]*j;
			s[i][j]%=M;
		}
	LL ans=0;
	FOR(i,0,n){
		LL A=pw(2,pw(2,n-i,M-1),M)*c[n][i]%M;
		
		//cout<<A<<endl;
		FOR(j,0,i){
			LL B=pw(2,1LL*(n-i)*j%(M-1),M);
			if(i&1){
				ans=ans-A*B%M*s[i+1][j+1]%M+M;
				ans%=M;
			}
			else{
				ans=ans+A*B%M*s[i+1][j+1]%M;
				ans%=M;
			}
		}
	}
	cout<<(ans+M)%M<<endl;
}
/*
題意:
N個東西的組合2^N S
其中 2^S 的集合中 滿足N個東西都出現>=2的條件數
如 2(A,B) 
ans=2
1. {A},{B},{AB}
2. {},{A},{B},{AB}
A,B 都出現2次以上

題解:
https://img.atcoder.jp/arc096/editorial.pdf

inclusion-exclusion principle
其中way(i)=
j(0,i)
S[i+1][j+1]* 2^(2^(n-i))[考慮前i和剩餘的] * 2^((n-i)*j) [只考慮剩餘的]
S[][]斯特靈數2
算上空集合 因此用s[i+1][j+1]來包含空集合
費馬定理 a^(p-1)=1 mod p
所以 a^(b^c)%m=a^((b^c%m)))%m=a^(b^(c%(m-1)))%m




*/
