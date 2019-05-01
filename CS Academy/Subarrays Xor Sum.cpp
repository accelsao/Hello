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
using namespace std;
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
const int N=1e5+1;
const int M=1e9+7;
int n,a,b;
int dp[30][2];
void add(int t,int x){
	REP(i,30)
		dp[i][(t>>i)&1]+=x;
}
int find(int t){
	LL s=0;
	REP(i,30)
		s=s+dp[i][1^(t>>i)&1]*(1LL<<i),s%=M;
	return s;
}
int main(){Accel
    cin>>n>>a>>b;
    vector<int>v(n+1);
    FOR(i,1,n)cin>>v[i];
    FOR(i,2,n)v[i]^=v[i-1];
    LL s=0;
    FOR(i,a,n){
		if(i>b)add(v[i-b-1],-1);
		add(v[i-a],1);
		s=(s+find(v[i]))%M;
		//cout<<s<<endl;
	}
	cout<<s<<endl;
}
