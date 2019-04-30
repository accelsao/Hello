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
const int N=1e5+1;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
LL n,p,q,r,a[N];
LL dp[N][3];
int main(){Accel
	cin>>n>>p>>q>>r;
	FOR(i,1,n)cin>>a[i];
	LL A,b,c;
	A=p*a[1],b=A+q*a[1],c=b+r*a[1];
	FOR(i,2,n){
		A=max(A,p*a[i]);
		b=max(b,A+q*a[i]);
		c=max(c,b+r*a[i]);
	}
	cout<<c<<endl;
}
