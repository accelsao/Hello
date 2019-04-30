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
#define MID ((l+r)>>1)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define ls lc,l,MID
#define rs rc,MID+1,r
#define st 1,1,n
#define PII pair<int,int>
#define PLL pair<LL,LL>
using namespace std;
const int N=1001;
const int M=1e9+7;
LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int k,a,b;
LL dp[N][N];
int main(){Accel
	cin>>k>>a>>b;
	LL A,B,C;
	A=a*pw(a+b,M-2,M)%M;
	B=(1-A+M)%M;
	C=A*pw(B,M-2,M)%M;
	for(int i=k;i;i--)
		for(int j=k-1;~j;j--)
			dp[i][j]=(j+i>=k?i+j+C:A*dp[i+1][j]+dp[i][j+i]*B)%M;
	cout<<dp[1][0]<<endl;	
}
