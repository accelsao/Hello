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
const int N=2e3+1;
const int M=1e9+7;
const double eps=1e-6;
//void add(int x){while(x<N)BIT[x]++,x+=x&-x;}
//int sum(int x){return x?BIT[x]+sum(x-(x&-x)):0;}
//int find(int x){return x==p[x]?x:p[x]=find(p[x]);}
//LL pw(LL a, LL b,LL M) { return b ? b & 1 ? a*pw(a, b - 1,M) % M : pw(a*a%M, b>>1,M) : 1; }
int n,x,t;
int dp[2][N];
int main(){Accel
    cin>>n;
    dp[t][1]=1;
    FOR(i,2,n){
		cin>>x;
		if(x){
			FOR(j,2,i){
			    dp[t^1][j]=dp[t^1][j-1]+dp[t][j-1];
			    dp[t^1][j]%=M;
			}
		}
		else{
			for(int j=i-1;j>=1;j--){
				dp[t^1][j]=dp[t^1][j+1]+dp[t][j];
			    dp[t^1][j]%=M;
			}
		}
		FOR(j,1,i)dp[t][j]=0;
		t^=1;
	}
	s=0;
	FOR(i,1,n)s+=dp[t][i],s%=M;
	cout<<s<<endl;
}
