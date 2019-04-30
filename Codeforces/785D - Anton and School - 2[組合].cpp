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
const int N=2e5+1;
const int M=1e9+7;
const double eps=1e-6;
const double PI(acos(-1.0));
//for(int mask=i;mask>0;mask=(mask-1)&i)
//size() use int
//__gcd, atan2(y,x)=y/x , __int128
//int a[25]= { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };
//c(n,k)=c(n-1,k-1)+c(n-1,k)
//c(i,r),i for r to n =c(n+1,r+1)
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//log() = ln() , log(x)/log(y)=log(y)-base-x
//watch out LL
//INT_MAX 127,INT_MIN 128
string s;
LL g[N],inv[N];
int p[N],f[N];
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int C(int n, int m) {
	if(n<m)return 0;
    return g[n] * inv[m] % M * inv[n-m] % M;
}
int main(){Accel
	LL ans=0;
	cin>>s;
	g[0]=inv[0]=g[1]=inv[1]=1;
	FOR(i,2,SZ(s)){
		g[i]=g[i-1]*i%M;
		inv[i]=pw(g[i],M-2,M);
	}	
	REP(i,SZ(s)){
		f[i]=s[i]=='(';
		if(i)
			f[i]+=f[i-1];
	}
	int cnt=0;
	for(int i=SZ(s)-1;~i;i--){
		if(s[i]==')')cnt++;
		else{
			LL x=f[i];
			LL y=cnt;
			ans=ans+C(x+y-1,x);
			ans%=M;
		}
	}
	cout<<ans<<endl;
}
